#include "HeaderAttribute.h"

using namespace std;

/*************************************/
/*************************************/
/** S T A T I C  C O N S T A N T S  **/
/*************************************/

string HeaderAttribute::unit_str = "-unit";
string HeaderAttribute::val_str = "-value";

/********************************************/
/** E N D  S T A T I C  C O N S T A N T S  **/
/********************************************/
/********************************************/
    


/*****************************/	
/*****************************/
/** C O N S T R U C T O R S **/
/*****************************/
    
//default constructor  
HeaderAttribute::HeaderAttribute() {}
    
    
//2nd constuctor
HeaderAttribute::HeaderAttribute(string initial_name)
{ 
    name = initial_name; 
}  
  
//3nd constuctor
HeaderAttribute::HeaderAttribute(string init_name, string init_unit, string init_value)
{ 
    name = init_name; 
    unit = init_unit; 
    value = init_value; 
}  
  
//copy constructor
HeaderAttribute::HeaderAttribute(const HeaderAttribute& hdrA)
{
    name = hdrA.name;
    unit = hdrA.unit;
    value = hdrA.value;
}
    
    
//deconstructor
HeaderAttribute::~HeaderAttribute() { }
    
/************************************/
/** E N D  C O N S T R U C T O R S **/
/************************************/
/************************************/	
   


/********************************/
/********************************/
/** P U B L I C  M E T H O D S **/
/********************************/
    
/*------------------------------------------------------------------

	Method:		clear
		
	Purpose:	Clears object to original (blank) state
		
------------------------------------------------------------------*/
    
void HeaderAttribute::clear()
{
    name.empty();
    unit.empty();
    value.empty();
      
}//end clear method
  
/***************************************/
/** E N D  P U B L I C  M E T H O D S **/
/***************************************/
/***************************************/



/**********************************/
/**********************************/
/** P R I V A T E  M E T H O D S **/
/**********************************/

//NONE

/*****************************************/
/** E N D  P R I V A T E  M E T H O D S **/
/*****************************************/
/*****************************************/



/********************************************/
/********************************************/
/** O V E R L O A D E D  O P E R A T O R S **/
/********************************************/		
    
void HeaderAttribute::operator= (HeaderAttribute hdrA)
{
    //cout<<"LatLonField operator="<<endl;
    name = hdrA.name;
    unit = hdrA.unit;      
    value = hdrA.value;
    
}//end operator= method

/***************************************************/
/** E N D  O V E R L O A D E D  O P E R A T O R S **/
/***************************************************/
/***************************************************/

//End Class HeaderAttribute




