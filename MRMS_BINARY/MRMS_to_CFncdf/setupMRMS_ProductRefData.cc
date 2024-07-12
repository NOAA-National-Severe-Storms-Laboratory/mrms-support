#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

#include "ProductInfo.h"

using namespace std;


// C O N S T A N T S
// none

   
// F U N C T I O N  P R O T O T Y P E S
// none


// F U N C T I O N S 

/*------------------------------------------------------------------

	Method:		setupMRMS_ProductRefData
	
	
	Purpose:	Using literal constants, setup the vector of 
	            ProductRefData
	
	Input:      n/a
	                               
	Output:		vector of ProductInfo objects containing entries
	            explicitly defined in the function
	            
------------------------------------------------------------------*/

vector<ProductInfo> setupMRMS_ProductRefData( )
{

    /*--------------------------*/
    /*** 1. Declare variables ***/
    /*--------------------------*/
   
    vector<ProductInfo> pInfo;
    pInfo.clear();
    
    float unkwn = ProductInfo::UNDEFINED;
    


    /*----------------------------------*/
    /*** 2. Add to the product vector ***/
    /*----------------------------------*/

    //ProductInfo::ProductInfo(string vN, string vU, float vM, float vNC, float fT,
    //                   string cN, string cLN, string cU, float cM, float cNC)
    //pInfo.push_back( ProductInfo( "", "", unkwn, -999, 0, "", "", "", unkwn, unkwn) );

    //Model fields --Add more?
    pInfo.push_back( ProductInfo( "0C_height", "mete", unkwn, -99, 0, "Model_FreezingLevel", "meter", "Freezing Height Radar mMSL", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "Dew_Point_T", "C", unkwn, -99, 0, "Model_DewPoint", "Celsius", "Model Surface Dew Point Temperature", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "T_model_sfc", "C", unkwn, -99, 0, "Model_SurfaceTemp", "Celsius", "Model Surface Temperature", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "WBT", "C_Deg", unkwn, -99, 0, "Model_WetBulbTemp", "Celsius", "Model Surface Wet Bulb Temperature", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "WarmRainProbs", "perce", unkwn, -99, 0, "Model_WarmRainProbs", "percent", "Probability of Warm Rain Processes", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "Precip_Water", "mm", unkwn, -99, 0, "Model_PrecipWater", "mm", "Precipitable Water", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "Precip_Eff", "mm", unkwn, -99, 0, "Model_PrecipEff", "mm", "Precipitation Efficiency", unkwn, unkwn) );


    //Brightband Heights
    pInfo.push_back( ProductInfo( "bb_bottom_height", "m", unkwn, -999, 0, "BB_BOTTOM", "meters", "Brightband Top Radar/RUC derived", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "bb_top_height", "m", unkwn, -999, 0, "BB_TOP", "meters", "Brightband Bottom Radar/RUC derived", unkwn, unkwn) );


    //3D Reflectivity data (3D and 2D sets)
    //How to handle 3D output vs 2D?
    pInfo.push_back( ProductInfo( "mosaicked_refl", "dbz", -99, -999, 0, "MREFL", "dBZ", "Mosaicked Reflectivity", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "mosaicked_kdp", "degre", -20, -30, 0, "MKDP", "degrees", "Mosaicked Kdp", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "mosaicked_rhohv", "none", -99, -999, 0, "MRHOHV", "none", "Mosaicked RhoHV", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "mosaicked_spw", "m/sec", -99, -999, 0, "MSPW", "m/s", "Mosaicked Spectrumwidth", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "mosaicked_zdr", "db", -99, -999, 0, "MZDR", "dB", "Mosaicked Zdr", unkwn, unkwn) );
    
    
    //2D products derived from 3D reflectivity
    pInfo.push_back( ProductInfo( "CREF", "dBZ", -99, -999, 0, "CREF", "dBZ", "Composite Reflectivity", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "CREFH", "m", -1, -999, 0, "CREFH", "kilometers", "Composite Reflectivity Height - kmMSL", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "LCR_LOW", "dBZ", -99, -999, 0, "LCR_LOW", "dBZ", "Layer Composite Reflectivity Mosaic 0-24kft (low altitude)", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "LCR_HIGH", "dBZ", -99, -999, 0, "LCR_HIGH", "dBZ", "Layer Composite Reflectivity Mosaic 24-60kft (highest altitude)", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "LCR_SUPER", "dBZ", -99, -999, 0, "LCR_SUPER", "dBZ", "Layer Composite Reflectivity Mosaic 33-60kft (super high altitude)", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "ETP", "km", -1, -999, 0, "ETP", "kilometers", "Echo Top 18dBZ Mosaic - kmMSL", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "STRMTOP", "km", -1, -999, 0, "STRMTOP", "kilometers", "Storm Top 30dBZ Mosaic - kmMSL", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "MEHS", "mm", -99, -999, 0, "MEHS", "mm", "Max Expected Hail Size", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "SHI", "none", -99, -999, 0, "SHI", "none", "Severe Hail Index", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "POSH", "none", -99, -999, 0, "POSH", "none", "Probability of Severe Hail", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "LCREF", "dBZ", -99, -999, 0, "LCREF", "dBZ", "Low-Level Composite Reflectivity (0-4km)", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "LCREFH", "m", -1, -999, 0, "LCREFH", "kilometers", "Low-Level Composite Reflectivity Height - kmMSL", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "VIL", "kg/m2", -99, -999, 0, "VIL", "kg/m2", "Vertically Integrated Liquid", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "VILD", "g/m3", -99, -999, 0, "VILD", "g/m3", "Vertically Integrated Liquid Density", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "TREFL_0C", "dBZ", -99, -999, 0, "TREFL_0C", "dBZ", "Reflectivity at the Height of 0 degC isotherm", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "TREFL_-10C", "dBZ", -99, -999, 0, "TREFL_-10C", "dBZ", "Reflectivity at the Height of -10 degC isotherm", unkwn, unkwn) );


    //2D Mosaics
    pInfo.push_back( ProductInfo( "UNQC_CREF", "dBZ", -99, -999, 0, "UNQC_CREF", "dBZ", "UnQC'd Composite Reflectivity Mosaic 0-60kft (max ref)", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "BASE_REFL", "dBZ", -99, -999, 0, "BASE_REFL", "dBZ", "Mosaic Base Reflectivity (optimal method)", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "CREF_MAX", "dBZ", -99, -999, 0, "CREF_MAX", "dBZ", "Composite Reflectivity Mosaic 0-60kft (max ref)", unkwn, unkwn) );

    
    //Seamless HSR based products
    pInfo.push_back( ProductInfo( "RADCOVERID", "flag", -1, unkwn, 0, "RADCOVERID", "none", "Radar Coverage ID", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "RQI", "index", -1, -999, 0, "RQI", "none", "Radar Quality Index", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "SHSRH", "kmAGL", -1, -1, 0, "SHSRH", "kilometers", "Height of Hybrid Scan Reflectivity - kmAGL", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "SHSR", "dBZ", -99, -999, 0, "SHSR", "dBZ", "Seamless Hybrid Scan Reflectivity Mosaic", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "SHSR_NOVPRC", "dBZ", -99, -999, 0, "SHSR_NOVPRC", "dBZ", "Seamless Hybrid Scan Reflectivity Mosaic without VPR Correction", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "SHSR_NOADJ", "dBZ", -99, -999, 0, "SHSR_NOADJ", "dBZ", "Seamless Hybrid Scan Reflectivity Mosaic without power adjustements or VPR Correction", unkwn, unkwn) );


    //Precip flag
    pInfo.push_back( ProductInfo( "PCP_PHASE", "flag", 0, -1, 0, "PCP_PHASE", "none", "Precip phase (noprecip=0; liquid=1; frozen=3; )", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "PCPFLAG", "flag", 0, -1, 0, "PCP_FLAG", "none", "Precip flag (noprecip=0; stratiform=1; brightband=2; snow=3; overshooting=4; convective=6; hail=7; cold stratiform=10; stratiform ID'd as tropical=91; convective ID'd as tropical=96)", unkwn, unkwn) );

    
    //QPEs -- check all missing values
    //pInfo.push_back( ProductInfo( "", "", -99, -999, 0, "", "", "", unkwn, unkwn) );
    //Q3 radar-only
    pInfo.push_back( ProductInfo( "preciprate", "mm/hr", 0, -999, 0, "PRECIPRATE", "mm/hr", "Precipitation Rate based on SHSR", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "rad_1h", "mm", 0, -999, 0, "RAD_1H", "mm", "Precipitation 1-hour Accumulation based on SHSR", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "rad_6h", "mm", 0, -999, 0, "RAD_6H", "mm", "Precipitation 6-hour Accumulation based on SHSR", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "rad_24h", "mm", 0, -999, 0, "RAD_24H", "mm", "Precipitation 24-hour Accumulation based on SHSR", unkwn, unkwn) );
    //Q3 radar-only without VPR correction
    pInfo.push_back( ProductInfo( "preciprate.novprc", "mm/hr", 0, -999, 0, "PRECIPRATE_NOVPRC", "mm/hr", "Precipitation Rate based on SHSR without VPR Correction", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "rad_novprc_1h", "mm", 0, -999, 0, "RAD_NOVPRC_1H", "mm", "Precipitation 1-hour Accumulation based on SHSR without VPR Correction", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "rad_novprc_6h", "mm", 0, -999, 0, "RAD_NOVPRC_6H", "mm", "Precipitation 6-hour Accumulation based on SHSR without VPR Correction", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "rad_novprc_24h", "mm", 0, -999, 0, "RAD_NOVPRC_24H", "mm", "Precipitation 24-hour Accumulation based on SHSR without VPR Correction", unkwn, unkwn) );
    //Q3 radar-only: synthetic radar-only + evap corrected
    pInfo.push_back( ProductInfo( "preciprate.evap", "mm/hr", 0, -999, 0, "PRECIPRATE_EVAP", "mm/hr", "Evaporation Corrected Precipitation Rate", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "15MRAD.EVAP", "mm", 0, -999, 0, "RAD_EVAP_15M", "mm", "Evaporation Corrected Precipitation 15-minute Accumulation ", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "rad_evap_1h", "mm", 0, -999, 0, "RAD_EVAP_1H", "mm", "Evaporation Corrected Precipitation 1-hour Accumulation ", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "rad_evap_3h", "mm", 0, -999, 0, "RAD_EVAP_3H", "mm", "Evaporation Corrected Precipitation 3-hour Accumulation ", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "rad_evap_6h", "mm", 0, -999, 0, "RAD_EVAP_6H", "mm", "Evaporation Corrected Precipitation 6-hour Accumulation ", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "rad_evap_12h", "mm", 0, -999, 0, "RAD_EVAP_12H", "mm", "Evaporation Corrected Precipitation 12-hour Accumulation ", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "rad_evap_24h", "mm", 0, -999, 0, "RAD_EVAP_24H", "mm", "Evaporation Corrected Precipitation 24-hour Accumulation ", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "rad_evap_48h", "mm", 0, -999, 0, "RAD_EVAP_48H", "mm", "Evaporation Corrected Precipitation 48-hour Accumulation ", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "rad_evap_72h", "mm", 0, -999, 0, "RAD_EVAP_72H", "mm", "Evaporation Corrected Precipitation 72-hour Accumulation ", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "rad_evap_since12z", "mm", 0, -999, 0, "RAD_EVAP_SINCE_12Z", "mm", "Evaporation Corrected Precipitation Since 12Z Accumulation ", unkwn, unkwn) );
    //Q3 LGC Gauge-adjusted
    pInfo.push_back( ProductInfo( "1HGC", "mm", -99, -999, 0, "GC_1H", "mm", "Gauge Corrected Precipitation 1-hour Accumulation based on SHSR", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "q3rad_gc_1h", "mm", -99, -999, 0, "GC_1H", "mm", "Gauge Corrected Precipitation 1-hour Accumulation based on SHSR", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "q3rad_gc_6h", "mm", -99, -999, 0, "GC_6H", "mm", "Gauge Corrected Precipitation 6-hour Accumulation based on SHSR", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "q3rad_gc_24h", "mm", -99, -999, 0, "GC_24H", "mm", "Gauge Corrected Precipitation 24-hour Accumulation based on SHSR", unkwn, unkwn) );
    //Q3 LGC Gauge-only
    pInfo.push_back( ProductInfo( "gauge_1h", "mm", -99, -999, 0, "GAUGE_1H", "mm", "Gauge Precipitation 1-hour Accumulation", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "gauge_6h", "mm", -99, -999, 0, "GAUGE_6H", "mm", "Gauge Precipitation 6-hour Accumulation", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "gauge_24h", "mm", -99, -999, 0, "GAUGE_24H", "mm", "Gauge Precipitation 24-hour Accumulation", unkwn, unkwn) );
    //Q3 Mountain Mapper
    pInfo.push_back( ProductInfo( "mmapper_1h", "mm", -99, -999, 0, "MNTMAPPER_1H", "mm", "Mountian Mapper Precipitation 1-hour Accumulation", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "mmapper_6h", "mm", -99, -999, 0, "MNTMAPPER_6H", "mm", "Mountian Mapper Precipitation 6-hour Accumulation", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "mmapper_24h", "mm", -99, -999, 0, "MNTMAPPER_24H", "mm", "Mountian Mapper Precipitation 24-hour Accumulation", unkwn, unkwn) );
    //Q3 MultiSensor
    pInfo.push_back( ProductInfo( "ms_1h", "mm", 0, -999, 0, "MS_1H", "mm", "MultiSensor Precipitation 1-hour Accumulation", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "ms_3h", "mm", 0, -999, 0, "MS_3H", "mm", "MultiSensor Precipitation 3-hour Accumulation", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "ms_6h", "mm", 0, -999, 0, "MS_6H", "mm", "MultiSensor Precipitation 6-hour Accumulation", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "ms_12h", "mm", 0, -999, 0, "MS_12H", "mm", "MultiSensor Precipitation 12-hour Accumulation", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "ms_24h", "mm", 0, -999, 0, "MS_24H", "mm", "MultiSensor Precipitation 24-hour Accumulation", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "ms_48h", "mm", 0, -999, 0, "MS_48H", "mm", "MultiSensor Precipitation 48-hour Accumulation", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "ms_72h", "mm", 0, -999, 0, "MS_72H", "mm", "MultiSensor Precipitation 72-hour Accumulation", unkwn, unkwn) );
    
    //Gauge-correction QPEs and related fields
    pInfo.push_back( ProductInfo( "QCMASK.CREF", "flag", unkwn, -999, 0, "CREF_QCMASK", "none", "Quality Control Mask based on composite reflectivity (values=0,1)", unkwn, unkwn) );    
    pInfo.push_back( ProductInfo( "FIELDMAX.CREF", "dBZ", -99, -999, 0, "FIELDMAX_CREF", "dBZ", "Maximum composite reflectivity value over the last 1-hour", unkwn, unkwn) );    
    
    
    //NEXTGEN-specific products
    pInfo.push_back( ProductInfo( "AZ_SHEAR_2KM", "1/sec", -1, -2, 0, "AZ_SHEAR_2KM", "1/sec", "Azimuth Shear 0-2km AGL", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "AZ_SHEAR_2KM_MAX", "1/sec", -1, -2, 0, "AZ_SHEAR_2KM_MAX", "1/sec", "Azimuth Shear 0-2km AGL 30-minute Max", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "AZ_SHEAR_6KM", "1/sec", -1, -2, 0, "AZ_SHEAR_6KM", "1/sec", "Azimuth Shear 3-6km AGL", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "AZ_SHEAR_6KM_MAX", "1/sec", -1, -2, 0, "AZ_SHEAR_6KM_MAX", "1/sec", "Azimuth Shear 3-6km AGL 30-minute Max", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "HAILSWATH", "mm", -99, -999, 0, "HAILSWATH", "mm", "MESH 30-min Max Swath (HailSwath)", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "CREF_30MIN_FCST", "dBZ", -99, -999, 1800, "CREF_30MIN_FCST", "dBZ", "30-min Forecast Composite Reflectivity Mosaic 0-60kft", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "VIL_30MIN_FCST", "kg/m^", -99, -999, 1800, "VIL_30MIN_FCST", "kg/m2", "30-min Forecast VIL", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "LTG_DENSITY", "1/(mi", -1, -2, 0, "LTG_DENSITY", "1/(minkm2)", "Lightning Density", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "LTG_30MIN_PROB", "dimen", -1, -2, 1800, "LTG_30MIN_PROB", "percent", "Lightning Probability 0-30min", unkwn, unkwn) );


    //Legacy NMQ products (deprecated in MRMS) 
 /*   
    pInfo.push_back( ProductInfo( "HSR", "dBZ", -99, -999, 0, "HSR", "dBZ", "Hybrid Scan Reflectivity", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "HSRH", "kmAGL", -1, unkwn, 0, "HSRH", "kilometers", "Height of Hybrid Scan Reflectivity - kmAGL", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "PCPTYPE", "flag", -1, -999, 0, "PCPTYPE", "none", "Precipitation Type - Frozen/Liquid", unkwn, unkwn) );

    pInfo.push_back( ProductInfo( "SHSR_VPRC", "dBZ", -99, -999, 0, "SHSR_VPRC", "dBZ", "VPR Corrected Hybrid Scan Reflectivity Mosaic", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "SHSR_POW", "dBZ", -99, -999, 0, "SHSR_VPRC", "dBZ", "Power Adjusted Hybrid Scan Reflectivity Mosaic", unkwn, unkwn) );

    pInfo.push_back( ProductInfo( "preciprate_hsr", "mm/hr", 0, -999, 0, "PRECIPRATE_HSR", "mm/hr", "Precipitation Rate HSR", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "1h_rad_hsr", "mm", 0, -999, 0, "RAD_HSR_1H", "mm", "Precipitation 1-hour Accumulation HSR", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "3h_rad_hsr", "mm", 0, -999, 0, "RAD_HSR_3H", "mm", "Precipitation 3-hour Accumulation HSR", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "6h_rad_hsr", "mm", 0, -999, 0, "RAD_HSR_6H", "mm", "Precipitation 6-hour Accumulation HSR", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "12h_rad_hsr", "mm", 0, -999, 0, "RAD_HSR_12H", "mm", "Precipitation 12-hour Accumulation HSR", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "24h_rad_hsr", "mm", 0, -999, 0, "RAD_HSR_24H", "mm", "Precipitation 24-hour Accumulation HSR", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "48h_rad_hsr", "mm", 0, -999, 0, "RAD_HSR_48H", "mm", "Precipitation 48-hour Accumulation HSR", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "72h_rad_hsr", "mm", 0, -999, 0, "RAD_HSR_72H", "mm", "Precipitation 72-hour Accumulation HSR", unkwn, unkwn) );
*/
    pInfo.push_back( ProductInfo( "1h_mmapper", "mm", -99, -999, 0, "MNTMAPPER_1H", "mm", "Mountian Mapper Precipitation 1-hour Accumulation", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "3h_mmapper", "mm", -99, -999, 0, "MNTMAPPER_3H", "mm", "Mountian Mapper Precipitation 3-hour Accumulation", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "6h_mmapper", "mm", -99, -999, 0, "MNTMAPPER_6H", "mm", "Mountian Mapper Precipitation 6-hour Accumulation", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "12h_mmapper", "mm", -99, -999, 0, "MNTMAPPER_12H", "mm", "Mountian Mapper Precipitation 12-hour Accumulation", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "24h_mmapper", "mm", -99, -999, 0, "MNTMAPPER_24H", "mm", "Mountian Mapper Precipitation 24-hour Accumulation", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "48h_mmapper", "mm", -99, -999, 0, "MNTMAPPER_48H", "mm", "Mountian Mapper Precipitation 48-hour Accumulation", unkwn, unkwn) );
    pInfo.push_back( ProductInfo( "72h_mmapper", "mm", -99, -999, 0, "MNTMAPPER_72H", "mm", "Mountian Mapper Precipitation 72-hour Accumulation", unkwn, unkwn) );


    //Third party QPEs
    //Stage IV 1-hr QPE
    pInfo.push_back( ProductInfo( "total_precip", "mm", -99, -999, 0, "STAGE4_1H", "mm", "Stage IV 1-hour Accumulation", unkwn, unkwn) );



    /*-------------------------------------*/   
    /*** 3. Free-up memory and/or return ***/
    /*-------------------------------------*/  
    
    return pInfo;
   
}//end function setupMRMS_ProductRefData

