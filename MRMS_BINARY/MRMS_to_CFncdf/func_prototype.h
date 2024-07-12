#ifndef FUNC_PROTOTYPE_H
#define FUNC_PROTOTYPE_H

#include <vector>
#include <string>

#include "ProductInfo.h"
#include "HeaderAttribute.h"

using namespace std;

vector<ProductInfo> setupMRMS_ProductRefData( );
                   
short int* mrms_binary_reader_cart3d(const char *vfname,                     
                     char *varname, char *varunit,
                     int &nradars, vector<string> &radarnam,
                     int &var_scale, int &missing_val,
                     float &nw_lon, float &nw_lat,
                     int &nx, int &ny, float &dx, float &dy,
                     float zhgt[], int &nz, long &epoch_seconds,
                     int swap_flag);
                   
int write_CF_netCDF_2d( string outputfile, string dataType, 
                   string longName, string varName, string varUnit,
                   int nx, int ny, float dx, float dy, 
                   float nw_lat, float nw_lon, float height,
                   long epoch_time, float fractional_time,
                   string cf_time_string, long cf_fcst_length,
                   vector<HeaderAttribute>& attrs, 
                   float missing_value, float range_folded_value,
                   float* data_1D, int gzip_flag);
                   
int write_CF_netCDF_2d_FAA( string outputfile, string dataType, 
                   string longName, string varName, string varUnit,
                   int nx, int ny, float dx, float dy, 
                   float nw_lat, float nw_lon, float height,
                   long epoch_time, float fractional_time,
                   string cf_time_string, long cf_fcst_length,
                   vector<HeaderAttribute>& attrs, 
                   float missing_value, float range_folded_value,
                   float* data_1D, int gzip_flag);
                   
int write_CF_netCDF_3d( string outputfile, string dataType, 
                   string longName, string varName, string varUnit,
                   int nx, int ny, int nz, float dx, float dy, 
                   float nw_lat, float nw_lon, float heights[],
                   long epoch_time, float fractional_time,
                   float missing_value, float range_folded_value,
                   float* data_1D, int gzip_flag );
                                      
int write_CF_netCDF_3d_FAA( string outputfile, string dataType, 
                   string longName, string varName, string varUnit,
                   int nx, int ny, int nz, float dx, float dy, 
                   float nw_lat, float nw_lon, float heights[],
                   long epoch_time, float fractional_time,
                   float missing_value, float range_folded_value,
                   float* data_1D, int gzip_flag );

void check_err(const int stat, const int line, const char *file);
int soft_check_err_wrt(const int stat, const int line, const char *file); 
int write_extra_attributes(int file_handle, int varID, vector<HeaderAttribute>& attrs);

#endif

