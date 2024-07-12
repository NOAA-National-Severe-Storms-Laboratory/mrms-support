#ifndef HEADERATTRIBUTE_H
#define HEADERATTRIBUTE_H

#include <string>

using namespace std;

/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

	File:		HeaderAttribute
	
	Date:		January 2006
	
	Author:		Carrie Langston (CIMMS/NSSL)
		
	Purpose:	Stores attribute information as it would be
	            found in a WDSS-II NetCDF file header
																
	_____________________________________________________________			
	Modification History:
       

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/

class HeaderAttribute
{
  public:
    static string unit_str;
    static string val_str;
  
    string name;
    string unit;
    string value;
    
    
    //default constructor  
    HeaderAttribute();
        
    //2nd and 3rd constuctor
    HeaderAttribute(string initial_name); 
    HeaderAttribute(string init_name, string init_unit, string init_value);
  
    //copy constructor
    HeaderAttribute(const HeaderAttribute& hdrA);
    
    //destructor
    ~HeaderAttribute();
    
    
    //clear
    void clear();
    
    void operator= (HeaderAttribute hdrA);
  
};
//end class HeaderAttribute

#endif

