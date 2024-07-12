#ifndef PRODUCTINFO_H
#define PRODUCTINFO_H

#include <string>
#include <iostream>

using namespace std;

/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

	File:		ProductInfo
	
	Date:		April 2011
	
	Author:		Carrie Langston (CIMMS/NSSL)
		
	Purpose:	Stores product information required to convert
	            HMRG binary files to WG-displayable WDSS-II NetCDF
																
	_____________________________________________________________			
	Modification History:
       

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/

class ProductInfo
{
  public:

    static const float UNDEFINED;
  
    string varName;
    string varUnit;
    float varMissing;
    float varNoCoverage;
    
    float fcstTime;
    
    string cfName;
    string cfUnit;
    string cfLongName;
    float cfMissing;
    float cfNoCoverage;
    
    
    //default constructor  
    ProductInfo();
        
    //2nd constuctor
    ProductInfo(string vN, string vU, float vM, float vNC, float fT,
                string cN, string cU, string cLN, float cM, float cNC); 
  
    //copy constructor
    ProductInfo(const ProductInfo& pI);
    
    //destructor
    ~ProductInfo();
    
    
    //public methods
    void setValues(string vN, string vU, float vM, float vNC, float fT,
                   string cN, string cU, string cLN, float cM, float cNC); 
    bool isMatch(string testName, string testUnit);
    bool incomplete();
    void clear();
    
    
    //overloaded operators
    void operator= (ProductInfo pI);
  
};
//end class ProductInfo

#endif

