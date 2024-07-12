#ifndef MRMS_BINARY_READER_H
#define MRMS_BINARY_READER_H

#include <iostream>
#include <fstream>
#include <zlib.h>
#include <vector>
#include <string>
#include <ctime>

using namespace std;


/*------------------------------------------------------------------

	Function:	byteswap (version 1)
		
	Purpose:	Perform byte swap operation on various data
	            types		
				
	Input:		data = some value
					
	Output:		value byte swapped
	
------------------------------------------------------------------*/
template < class Data_Type >
inline void byteswap( Data_Type &data )
{
  unsigned int num_bytes = sizeof( Data_Type );
  char *char_data = reinterpret_cast< char * >( &data );
  char *temp = new char[ num_bytes ];

  for( unsigned int i = 0; i < num_bytes; i++ )
  {
    temp[ i ] = char_data[ num_bytes - i - 1 ];
  }

  for( unsigned int i = 0; i < num_bytes; i++ )
  {
    char_data[ i ] = temp[ i ];
  }
  delete [] temp;
}
  


/*------------------------------------------------------------------

	Function:	byteswap (version 2)
		
	Purpose:	Perform byte swap operation on an array of
	            various data types		
				
	Input:		data = array of values
					
	Output:		array of byte swapped values
	
------------------------------------------------------------------*/
template < class Data_Type >
inline void byteswap( Data_Type *data_array, int num_elements )
{
  int num_bytes = sizeof( Data_Type );
  char *temp = new char[ num_bytes ];
  char *char_data;

  for( int i = 0; i < num_elements; i++ )
  {
    char_data = reinterpret_cast< char * >( &data_array[ i ] );

    for( int i = 0; i < num_bytes; i++ )
    {
      temp[ i ] = char_data[ num_bytes - i - 1 ];
    }

    for( int i = 0; i < num_bytes; i++ )
    {
      char_data[ i ] = temp[ i ];
    }
  }
  delete [] temp;
}



/*------------------------------------------------------------------

        Function:       make_time
                
        Purpose:        Convert a tm struct to epoch seconds            
                                
        Input:          tm struct with time and date set
                                        
        Output:         time_t with converted time in epoch seconds
        
------------------------------------------------------------------*/
time_t make_time(struct tm *tim)
{
    time_t timer=0;
    int i;
    int maxd[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    for(i=1970-1900;i<tim->tm_year;i++)
    {
        timer += 31536000l;
        if ((i%4)==0) timer += 86400l;
    }

    if ((tim->tm_year%4)==0) maxd[1] = 29;
    for(i=1;i<tim->tm_mon;i++)
        timer += (maxd[i-1]*86400l);
    for(i=1;i<tim->tm_mday;i++)
        timer += 86400l;
    for(i=0;i<tim->tm_hour;i++)
        timer += 3600l;
    for(i=0;i<tim->tm_min;i++)
        timer += 60l;
    for(i=0;i<tim->tm_sec;i++)
        timer ++;

    return timer;
}



/*------------------------------------------------------------------

	Function: mrms_binary_reader_cart3d
		
	Purpose:  Read a MRMS Cartesian binary file and return
              its header info and data.		
				
	Input:    vfname = input file name and path
	
              swap_flag = flag (= 0 or 1) indicating if values
                          read from the file should be byte 
                          swapped
                
                
	Output:   varname = Name of variable
	          varunit = Units of variable
	
	          nradars = Number of radars used in product
	          radarnam = List of radars used in product
	
	          var_scale = Value used to scale the variable data	
	          missing_val = Value to indicate missing data
	
	          nw_lon = Longitude of NW grid cell (center of cell)
	          nw_lat = Latitude of NW grid cell (center of cell)
	          
	          nx = Number of columns in field
	          ny = Number of rows in field
	          dx = Size of grid cell (degrees longitude)
	          dy = Size of grid cell (degrees latitude)
	          
	          zhgt = Height of vertical levels
	          nz = Number of vertical levels
	          
	          epoch_seconds = valid time for file expressed in 
	            epoch time (seconds since Jan. 1, 1970 00:00:00 UTC)
	            
	          binary_data = Variable data (scaled) in 1D array
	
------------------------------------------------------------------*/
short int* mrms_binary_reader_cart3d(char *vfname,                     
                     char *varname,char *varunit,
                     int &nradars, vector<string> &radarnam,
                     int &var_scale, int &missing_val,
                     float &nw_lon, float &nw_lat,
                     int &nx, int &ny, float &dx, float &dy,
                     float zhgt[], int &nz, long &epoch_seconds,
                     int swap_flag)

{

    /*--------------------------*/
    /*** 0. Declare variables ***/ 
    /*--------------------------*/
    
    short int *binary_data = 0;

    int yr,mo,day,hr,min,sec;
    int map_scale, dxy_scale, z_scale;
    char temp_varname[20];
    char temp_varunit[6];

    int temp;
    char chartemp[4];



    /*-------------------------*/
    /*** 1. Open binary file ***/ 
    /*-------------------------*/
        
    char open_mode[3];
    gzFile   fp_gzip;

    sprintf(open_mode,"%s","rb");
    open_mode[2] = '\0';

    if ( (fp_gzip = gzopen(vfname,open_mode) ) == (gzFile) NULL )
    {
      cout<<"+++ERROR: Could not open "<<vfname<<endl;
      return binary_data;
    }



    /*---------------------------------------*/
    /*** 2. Read binary header information ***/ 
    /*---------------------------------------*/
    
    //reading time
    gzread( fp_gzip, &yr,sizeof(int));  // 1-4
    if (swap_flag==1) byteswap(yr);
    
    gzread( fp_gzip, &mo,sizeof(int));  // 5-8 
    if (swap_flag==1) byteswap(mo);
    
    gzread( fp_gzip, &day,sizeof(int)); // 9-12
    if (swap_flag==1) byteswap(day);
    
    gzread( fp_gzip, &hr,sizeof(int));  // 13-16
    if (swap_flag==1) byteswap(hr);
    
    gzread( fp_gzip, &min,sizeof(int)); // 17-20
    if (swap_flag==1) byteswap(min);
    
    gzread( fp_gzip, &sec,sizeof(int)); // 21-24
    if (swap_flag==1) byteswap(sec);


    //Compute epoch seconds
    time_t  now;
    struct tm * gmt_file_time = gmtime(&now);
    gmt_file_time->tm_sec = sec;
    gmt_file_time->tm_min = min;
    gmt_file_time->tm_hour = hr;
    gmt_file_time->tm_mday = day;
    gmt_file_time->tm_mon  = mo;
    gmt_file_time->tm_year = yr-1900;
    gmt_file_time->tm_isdst = -1;

    epoch_seconds = make_time(gmt_file_time);


    //read dimensions
    gzread( fp_gzip,&temp,sizeof(int)) ;  // 25-28
    if (swap_flag==1) byteswap(temp);
    nx = temp;
    
    gzread( fp_gzip, &temp,sizeof(int)) ;  // 29-32
    if (swap_flag==1) byteswap(temp);
    ny = temp;
    
    gzread( fp_gzip, &temp,sizeof(int)) ;  // 33-36
    if (swap_flag==1) byteswap(temp);
    nz = temp;


    //read deprecated value (map projection type)
    gzread(fp_gzip,&chartemp,4*sizeof(char));  // 37-40


    //read map scale factor
    gzread(fp_gzip,&temp,sizeof(int));  // 41-44
    if (swap_flag==1) byteswap(temp);
    map_scale = temp;
      
      
    //read deprecated value (trulat1)
    gzread( fp_gzip,&temp,sizeof(int)) ;   // 45-48
    
    //read deprecated value (trulat2)
    gzread( fp_gzip, &temp,sizeof(int)) ;  // 49-52
    
    //read deprecated value (trulon)
    gzread( fp_gzip, &temp,sizeof(int)) ;  // 53-56
    
      
    //read nw lat/lon coordinates
    gzread(fp_gzip,&temp,sizeof(int));  // 57-60
    if (swap_flag==1) byteswap(temp);
    nw_lon = (float)temp/(float)map_scale;
    
    gzread(fp_gzip,&temp,sizeof(int));  // 61-64
    if (swap_flag==1) byteswap(temp);
    nw_lat = (float)temp/(float)map_scale;


    //read deprecated value (xy_scale)
    gzread(fp_gzip,&temp,sizeof(int));  // 65-68


    //read dx and dy    
    gzread(fp_gzip,&temp,sizeof(int));  // 69-72
    if (swap_flag==1) byteswap(temp);
    dx = (float)temp;

    gzread(fp_gzip,&temp,sizeof(int));  // 73-76
    if (swap_flag==1) byteswap(temp);
    dy = (float)temp;


    //read dx and dy scaling factor and unscale
    gzread(fp_gzip,&temp,sizeof(int));  // 77-80
    if (swap_flag==1) byteswap(temp);
    dxy_scale = temp;
      
    dx = dx/float(dxy_scale);
    dy = dy/float(dxy_scale);


    //read heights      
    for(int k=0; k<nz; k++)  // 81- [80+nz*4]  (let [80+nz*4] = X)
    {
      gzread(fp_gzip,&temp,sizeof(int));
      if (swap_flag==1) byteswap(temp);
      zhgt[k] = (float)temp;
    }


    //read z scale 
    gzread(fp_gzip,&temp,sizeof(int));  // [X+1] - [X+4]
    if (swap_flag==1) byteswap(temp);
    z_scale = temp;
    
    //Unscale heights, if needed
    if( (z_scale != 1) && (z_scale != 0) )
    {
      for(int k=0; k<nz; k++) zhgt[k] /= (float)z_scale;
    }
      
      
    //read junk (place holders for future use)
    for(int j = 0; j < 10; j++)  // [X+5] - [X+44]
    {
      gzread(fp_gzip,&temp,sizeof(int)); 
    }
      
      
    //read variable name
    gzread(fp_gzip,temp_varname,20*sizeof(char));  // [X+45] - [X+64]
    if (swap_flag==1) byteswap(temp_varname,20);    
    temp_varname[19]='\0';
    
    strcpy(varname, temp_varname);


    //read variable unit
    gzread(fp_gzip,temp_varunit,6*sizeof(char));  // [X+65] - [X+70]
    if (swap_flag==1) byteswap(temp_varunit,6);    
    temp_varunit[5]='\0';
    
    strcpy(varunit, temp_varunit);


    //read variable scaling factor
    gzread(fp_gzip,&var_scale,sizeof(int));  // [X+71] - [X+74]
    if (swap_flag==1) byteswap(var_scale);


    //read variable missing flag
    gzread(fp_gzip,&missing_val,sizeof(int));  // [X+75] - [X+78]
    if (swap_flag==1) byteswap(missing_val);


    //read number of radars affecting this product
    gzread(fp_gzip,&nradars,sizeof(int));  // [X+79] - [X+82]
    if (swap_flag==1) byteswap(nradars);
      
      
    //read in names of radars
    char temp_radarnam[5];
      
    for(int i=0;i<nradars;i++)  // [X+83] - [X+82+nradars*4]
    {
      gzread(fp_gzip,temp_radarnam,4*sizeof(char));
      if (swap_flag==1) byteswap(temp_radarnam,4);
      temp_radarnam[4]='\0';
      
      radarnam.push_back(temp_radarnam);
    }



    /*-------------------------*/
    /*** 3. Read binary data ***/ 
    /*-------------------------*/
    
    int num = nx*ny*nz;
    binary_data = new short int[num];
      
    //read data array    [X+83+nradars*4] - [X+82+nradars*4+num*2]
    gzread(fp_gzip,binary_data,num*sizeof(short int));  
    if (swap_flag==1) byteswap(binary_data,num);
      
      
      
    /*------------------------------*/
    /*** 4. Close file and return ***/ 
    /*------------------------------*/
   
    //close file      
    gzclose( fp_gzip );

    return binary_data;

}//end mrms_binary_reader_cart3d function

#endif
