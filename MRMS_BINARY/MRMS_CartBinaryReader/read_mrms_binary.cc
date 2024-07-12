#include <iostream>
#include <vector>
#include <string>

#include "mrms_binary_reader.h"

using namespace std;   

/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

	Program:	read_mrms_binary.cc
	            (newer version of read_nmq_binary.cc)
	
	Date:		July 2013
	
	Author:		Carrie Langston (CIMMS/NSSL)
	        	
	Purpose:	This program will read in a MRMS binary file,
	            reassign the 1D input to a 3D array, and
	            unscale the data field.
		
	Input:		2 command-line arguments:
					1) input file path and name
					2) swap byte flag 
					     = 0; no
					     = 1; yes
					     
	            NOTE: You may need to set the swap byte flag to 1  
	            if the OS you're using to read the binary file 
	            differs from the one used to write the file, 
	            such that the endain order differs (i.e., 
	            "Little Endian" vs. "Big Endian").  The program 
	            will likely crash if the swap flag is set
	            incorrectly (so you'll find out quickly if it
	            needs to be set to 0 or 1). 
	                  
	Output: 	Messages to standard output
				
				
	To Compile:	If using g++ compiler...
	            g++ -o read_mrms_binary read_mrms_binary.cc -lz
	           	
	To Run:		read_mrms_binary <input file> <swap flag>
																											
	_____________________________________________________________			
	Modification History:
	       
        12/08/2014  Carrie Langston (CIMMS/NSSL)
        - Updated nmq_binary_reader.h to correctly compute the
        data file's time in epoch seconds

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/


/************************************************/
/***  F U N C T I O N  P R O T O T Y P E (S)  ***/
/************************************************/

short int* mrms_binary_reader_cart3d(char *vfname,                     
                     char *varname,char *varunit,
                     int &nradars, vector<string> &radarnam,
                     int &var_scale, int &missing_val,
                     float &nw_lon, float &nw_lat,
                     int &nx, int &ny, float &dx, float &dy,
                     float zp[], int &nz, long &epoch_seconds,
                     int swap_flag);
                   
                   

/********************************/
/***  M A I N  P R O G R A M  ***/
/********************************/

int main(int argc,  char* argv[])
{
    cout<<"\n\n"<<endl;
    cout<<"      *************************************************"<<endl;
    cout<<"      *                                               *"<<endl;
    cout<<"      *          WELCOME TO MRMS BINARY READER        *"<<endl;
    cout<<"      *                   Dec  2014                   *"<<endl;
    cout<<"      *                                               *"<<endl;
    cout<<"      *************************************************"<<endl;
    cout<<endl;
    


    /*---------------------------------------*/
    /*** 0. Process command-line arguments ***/ 
    /*---------------------------------------*/

    //Process command-line arguments
    if(argc!=3)
    {
      cout<<"Usage:  read_mrms_binary /path/input_file swap_flag"<<endl;
      cout<<"        swap_flag = 0 or 1; see read_mrms_binary.cc "
          <<"header for more info"<<endl;
      cout<<"Exiting from read_mrms_binary."<<endl<<endl;
      exit(0);
    }

    char input_file[300];
    strcpy(input_file, argv[1]);

    int swap_flag = atoi(argv[2]);
    


    /*---------------------------------------------------*/
    /*** 1. Declare several variables needed by reader ***/
    /*---------------------------------------------------*/

    char varname[20];
    char varunit[6];
    int nradars;
    vector<string> radarnames;
    int var_scale, missing;
    float nw_lat, nw_lon;
    int nx, ny, nz;
    float dx, dy;
    float zhgt[50]; //assuming there will be <50 levels!
    long epoch_sec;

    short int* input_data_1D = 0;



    /*-------------------------*/
    /*** 2. Read input field ***/
    /*-------------------------*/

    //Read file
    input_data_1D = mrms_binary_reader_cart3d(input_file,                     
                           varname, varunit,
                           nradars, radarnames,
                           var_scale, missing,
                           nw_lon, nw_lat,
                           nx, ny, dx, dy,
                           zhgt, nz, epoch_sec, swap_flag);


    //Perform some error checking
    if(input_data_1D == 0)
    {
      cout<<"+++ERROR: Failed to read "<<input_file<<" Exiting!"<<endl;
      return 0;
    }
    cout<<"DONE reading file"<<endl<<endl;
    

    //Print out header info.
    cout<<"Binary Header Info:"<<endl;
    cout<<" variable name = "<<varname<<endl;
    cout<<" variable unit = "<<varunit<<endl;
    cout<<" number of radars = "<<nradars<<endl;
    
    cout<<" Radars: ";
    for(size_t i = 0; i < radarnames.size(); i++)
      cout<<radarnames[i]<<" ";
    cout<<endl;
    
    cout<<" variable scale = "<<var_scale<<endl;
    cout<<" missing value = "<<missing<<endl;
    cout<<" NW latitude = "<<nw_lat<<endl;
    cout<<" NW longitude = "<<nw_lon<<endl;
    cout<<" Number of columns = "<<nx<<endl;
    cout<<" Number of rows = "<<ny<<endl;
    cout<<" Number of levels = "<<nz<<endl;
    cout<<" Grid cell size (degree lat.) = "<<dy<<endl;
    cout<<" Grid cell size (degree lon.) = "<<dx<<endl;
    
    cout<<" Level heights (m MSL) = ";
    for(int i = 0; i < nz; i++) cout<<zhgt[i]<<" ";
    cout<<endl;
    
    char timestamp[20];
    strftime(timestamp, 20, "%m/%d/%Y %H%M%S", gmtime(&epoch_sec));
    cout<<" Time = "<<timestamp<<" UTC  (or "<<epoch_sec
        <<" epoch seconds)"<<endl<<endl;

      
    
    /*----------------------------------------------*/
    /*** 3. Reassign to 3D array and unscale data ***/
    /*----------------------------------------------*/
    
    //NOTE: The field's origin (data_3D[0][0][0]) is the SW corner's  
    //      lowest level.  As j increases so does the latitude.
    //NOTE: For 2D data nz = 1
    
    float ***data_3D = new float** [nz];
    for(int k = 0; k < nz; k++)
    {
      data_3D[k] = new float* [nx];
      for(int i = 0; i < nx; i++) data_3D[k][i] = new float [ny];
    }
    int index = -1;
    
    for(int k = 0; k < nz; k++)
    {
      for(int i = 0; i < nx; i++)
      {
        for(int j = 0; j < ny; j++)
        {
          index = k*nx*ny + j*nx + i;
          data_3D[k][i][j] = (float)input_data_1D[index] / (float)var_scale;
        } 
      }
    }
        
    

    /*------------------------*/
    /*** 4. Free-up Memory, ***/
    /*------------------------*/

    //memory clean-up
    if(input_data_1D != 0) delete [] input_data_1D;
        
    if(data_3D != 0)
    {
      for(int k = 0; k < nz; k++)
      {
        for(int i = 0; i < nx; i++) delete [] data_3D[k][i];
        delete [] data_3D[k];
      }
      delete [] data_3D;
    }
        

    return 1;
    
}//end main function




/**************************/
/*** F U N C T I O N S  ***/
/**************************/

//see mrms_binary_reader.h
