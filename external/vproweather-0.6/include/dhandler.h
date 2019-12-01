/****************************************************************************/
/*  vproweather 0.6															*/
/*	A program for acquiring data from a Davis Vantage Pro Weather Station.	*/
/*																			*/
/*  Thanks to Paul Davis for his 'remserial' program, and Aaron Logue's     */
/*  'weastat' program.														*/
/*																			*/
/* (c)2004 Joe Jaworski    email: jj@joejaworski.com						*/
/* VPROWEATHER is covered under the GNU general license. See the attached   */
/* LICENSE file for details.												*/
/*																			*/
/* This software is provided as-is, without any expressed or implied		*/
/* warranties, including, without limitation, the implied warranties of		*/
/* merchantibility and fitness for any particular purpose.					*/
/*																			*/
/*																			*/
/* dhandler.h - data handlers include file									*/
/* tabs every 4 places														*/
/*																			*/
/****************************************************************************/

#ifndef __DHANDLER_H__
#define __DHANDLER_H__

#include "main.h"

#ifdef __cplusplus
#define extern "C" {		/* respect c++ callers */
#endif

/* exports */
extern int CheckCRC(int nCnt, char *pData);
extern void GetRTData(char *szData);
extern void GetHLData(char *szData);
extern void PrintRTData(void);
extern void PrintHLData(void);
extern void PrintGDData(char * pData);
extern void PrintTime(char *szData);

extern char* ForecastString(WORD wRule);


/* graphic data sets- memory pointer offsets */	
#define GRAPH_START              177

#define NEXT_10MIN_PTR           GRAPH_START+1
#define NEXT_15MIN_PTR           GRAPH_START+2
#define NEXT_HOUR_PTR            GRAPH_START+3
#define NEXT_DAY_PTR             GRAPH_START+4
#define NEXT_MONTH_PTR           GRAPH_START+5
#define NEXT_YEAR_PTR            GRAPH_START+6
#define NEXT_RAIN_STORM_PTR      GRAPH_START+7
#define NEXT_RAIN_YEAR_PTR       GRAPH_START+8
#define GRF                      GRAPH_START+9
//                                                        NUMBER  NUMBER
//                                                        OF      OF
//                                                        ENTRYS  BYTES
//                                                        --------------
#define TEMP_IN_HOUR                 GRF +    0            // 24 ||  1
#define TEMP_IN_DAY_HIGHS            GRF +   24            // 24 ||  1
#define TEMP_IN_DAY_HIGH_TIMES       GRF +   48            // 24 ||  2
#define TEMP_IN_DAY_LOWS             GRF +   96            // 24 ||  1
#define TEMP_IN_DAY_LOW_TIMES        GRF +  120            // 24 ||  2
#define TEMP_IN_MONTH_HIGHS          GRF +  168            // 25 ||  1
#define TEMP_IN_MONTH_LOWS           GRF +  193            // 25 ||  1
#define TEMP_IN_YEAR_HIGHS           GRF +  218            //  1 ||  1
#define TEMP_IN_YEAR_LOWS            GRF +  219            //  1 ||  1

#define TEMP_OUT_HOUR                GRF +  220            // 24 ||  1
#define TEMP_OUT_DAY_HIGHS           GRF +  244            // 24 ||  1
#define TEMP_OUT_DAY_HIGH_TIMES      GRF +  268            // 24 ||  2
#define TEMP_OUT_DAY_LOWS            GRF +  316            // 24 ||  1
#define TEMP_OUT_DAY_LOW_TIMES       GRF +  340            // 24 ||  2
#define TEMP_OUT_MONTH_HIGHS         GRF +  388            // 25 ||  1
#define TEMP_OUT_MONTH_LOWS          GRF +  413            // 25 ||  1
#define TEMP_OUT_YEAR_HIGHS          GRF +  438            // 25 ||  1
#define TEMP_OUT_YEAR_LOWS           GRF +  463            // 25 ||  1

#define DEW_HOUR                     GRF +  488            // 24 ||  1
#define DEW_DAY_HIGHS                GRF +  512            // 24 ||  1
#define DEW_DAY_HIGH_TIMES           GRF +  536            // 24 ||  2
#define DEW_DAY_LOWS                 GRF +  584            // 24 ||  1
#define DEW_DAY_LOW_TIMES            GRF +  608            // 24 ||  2
#define DEW_MONTH_HIGHS              GRF +  656            // 25 ||  1
#define DEW_MONTH_LOWS               GRF +  681            // 25 ||  1
#define DEW_YEAR_HIGHS               GRF +  706            //  1 ||  1
#define DEW_YEAR_LOWS                GRF +  707            //  1 ||  1

#define CHILL_HOUR                   GRF +  708            // 24 ||  1
#define CHILL_DAY_LOWS               GRF +  732            // 24 ||  1
#define CHILL_DAY_LOW_TIMES          GRF +  756            // 24 ||  2
#define CHILL_MONTH_LOWS             GRF +  804            // 25 ||  1
#define CHILL_YEAR_LOWS              GRF +  829            //  1 ||  1

#define THSW_HOUR                    GRF +  830            // 24 ||  1
#define THSW_DAY_HIGHS               GRF +  854            // 24 ||  1
#define THSW_DAY_HIGH_TIMES          GRF +  878            // 24 ||  2
#define THSW_MONTH_HIGHS             GRF +  926            // 25 ||  1
#define THSW_YEAR_HIGHS              GRF +  951            //  1 ||  1

#define HEAT_HOUR                    GRF +  952            // 24 ||  1
#define HEAT_DAY_HIGHS               GRF +  976            // 24 ||  1
#define HEAT_DAY_HIGH_TIMES          GRF + 1000            // 24 ||  2
#define HEAT_MONTH_HIGHS             GRF + 1048            // 25 ||  1
#define HEAT_YEAR_HIGHS              GRF + 1073            //  1 ||  1

#define HUM_IN_HOUR                  GRF + 1074            // 24 ||  1
#define HUM_IN_DAY_HIGHS             GRF + 1098            // 24 ||  1
#define HUM_IN_DAY_HIGH_TIMES        GRF + 1122            // 24 ||  2
#define HUM_IN_DAY_LOWS              GRF + 1170            // 24 ||  1
#define HUM_IN_DAY_LOW_TIMES         GRF + 1194            // 24 ||  2
#define HUM_IN_MONTH_HIGHS           GRF + 1242            // 25 ||  1
#define HUM_IN_MONTH_LOWS            GRF + 1267            // 25 ||  1
#define HUM_IN_YEAR_HIGHS            GRF + 1292            //  1 ||  1
#define HUM_IN_YEAR_LOWS             GRF + 1293            //  1 ||  1

#define HUM_OUT_HOUR                 GRF + 1294            // 24 ||  1
#define HUM_OUT_DAY_HIGHS            GRF + 1318            // 24 ||  1
#define HUM_OUT_DAY_HIGH_TIMES       GRF + 1342            // 24 ||  2
#define HUM_OUT_DAY_LOWS             GRF + 1390            // 24 ||  1
#define HUM_OUT_DAY_LOW_TIMES        GRF + 1414            // 24 ||  2
#define HUM_OUT_MONTH_HIGHS          GRF + 1462            // 25 ||  1
#define HUM_OUT_MONTH_LOWS           GRF + 1487            // 25 ||  1
#define HUM_OUT_YEAR_HIGHS           GRF + 1512            //  1 ||  1
#define HUM_OUT_YEAR_LOWS            GRF + 1513            //  1 ||  1

#define BAR_15_MIN                   GRF + 1514            // 24 ||  2
#define BAR_HOUR                     GRF + 1562            // 24 ||  2
#define BAR_DAY_HIGHS                GRF + 1610            // 24 ||  2
#define BAR_DAY_HIGH_TIMES           GRF + 1658            // 24 ||  2
#define BAR_DAY_LOWS                 GRF + 1706            // 24 ||  2
#define BAR_DAY_LOW_TIMES            GRF + 1754            // 24 ||  2
#define BAR_MONTH_HIGHS              GRF + 1802            // 25 ||  2
#define BAR_MONTH_LOWS               GRF + 1852            // 25 ||  2
#define BAR_YEAR_HIGHS               GRF + 1902            //  1 ||  2
#define BAR_YEAR_LOWS                GRF + 1904            //  1 ||  2

#define WIND_SPEED_10_MIN_AVG        GRF + 1906            // 24 ||  1
#define WIND_SPEED_HOUR_AVG          GRF + 1930            // 24 ||  1
#define WIND_SPEED_DAY_HIGHS         GRF + 1954            // 24 ||  1
#define WIND_SPEED_DAY_HIGH_TIMES    GRF + 1978            // 24 ||  2
#define WIND_SPEED_DAY_HIGH_DIR      GRF + 2026            // 24 ||  1
#define WIND_SPEED_MONTH_HIGHS       GRF + 2050            // 25 ||  1
#define WIND_SPEED_MONTH_HIGH_DIR    GRF + 2075            // 25 ||  1
#define WIND_SPEED_YEAR_HIGHS        GRF + 2100            // 25 ||  1
#define WIND_SPEED_YEAR_HIGH_DIR     GRF + 2125            // 25 ||  1

#define WIND_DIR_HOUR                GRF + 2150            // 24 ||  1
#define WIND_DIR_DAY                 GRF + 2174            // 24 ||  1
#define WIND_DIR_MONTH               GRF + 2198            // 24 ||  1
#define WIND_DIR_DAY_BINS            GRF + 2222            //  8 ||  2
#define WIND_DIR_MONTH_BINS          GRF + 2238            //  8 ||  2

#define RAIN_RATE_1_MIN              GRF + 2254            // 24 ||  2
#define RAIN_RATE_HOUR               GRF + 2302            // 24 ||  2
#define RAIN_RATE_DAY_HIGHS          GRF + 2350            // 24 ||  2
#define RAIN_RATE_DAY_HIGH_TIMES     GRF + 2398            // 24 ||  2
#define RAIN_RATE_MONTH_HIGHS        GRF + 2446            // 25 ||  2
#define RAIN_RATE_YEAR_HIGHS         GRF + 2496            // 25 ||  2

#define RAIN_15_MIN                  GRF + 2546            // 24 ||  1
#define RAIN_HOUR                    GRF + 2570            // 24 ||  2
#define RAIN_STORM                   GRF + 2618            // 25 ||  2
#define RAIN_STORM_START             GRF + 2668            // 25 ||  2
#define RAIN_STORM_END               GRF + 2718            // 25 ||  2
#define RAIN_DAY_TOTAL               GRF + 2768            // 25 ||  2
#define RAIN_MONTH_TOTAL             GRF + 2818            // 25 ||  2
#define RAIN_YEAR_TOTAL              GRF + 2868            // 25 ||  2

#define ET_HOUR                      GRF + 2918            // 24 ||  1
#define ET_DAY_TOTAL                 GRF + 2942            // 25 ||  1
#define ET_MONTH_TOTAL               GRF + 2967            // 25 ||  2
#define ET_YEAR_TOTAL                GRF + 3017            // 25 ||  2

#define SOLAR_HOUR_AVG               GRF + 3067            // 24 ||  2
#define SOLAR_DAY_HIGHS              GRF + 3115            // 24 ||  2
#define SOLAR_DAY_HIGH_TIMES         GRF + 3163            // 24 ||  2
#define SOLAR_MONTH_HIGHS            GRF + 3211            // 25 ||  2
#define SOLAR_YEAR_HIGHS             GRF + 3261            //  1 ||  2

#define UV_HOUR_AVG                  GRF + 3263            // 24 ||  1
#define UV_MEDS_HOUR                 GRF + 3287            // 24 ||  1
#define UV_MEDS_DAY                  GRF + 3311            // 24 ||  1
#define UV_DAY_HIGHS                 GRF + 3335            // 24 ||  1
#define UV_DAY_HIGH_TIMES            GRF + 3359            // 24 ||  2
#define UV_MONTH_HIGHS               GRF + 3407            // 25 ||  1
#define UV_YEAR_HIGHS                GRF + 3432            //  1 ||  1

#define LEAF_HOUR                    GRF + 3433            // 24 ||  1
#define LEAF_DAY_LOWS                GRF + 3457            // 24 ||  1
#define LEAF_DAY_LOW_TIMES           GRF + 3481            // 24 ||  2
#define LEAF_DAY_HIGHS               GRF + 3529            // 24 ||  1
#define LEAF_DAY_HIGH_TIMES          GRF + 3553            // 24 ||  2
#define WIND_SPEED_HOUR_HIGHS        GRF + 3601            // 24 ||  1
#define LEAF_MONTH_LOWS              GRF + 3625            //  1 ||  1
#define LEAF_MONTH_HIGHS             GRF + 3626            // 25 ||  1
#define LEAF_YEAR_LOWS               GRF + 3651            //  1 ||  1
#define LEAF_YEAR_HIGHS              GRF + 3652            //  1 ||  1

#define SOIL_HOUR                    GRF + 3653            // 24 ||  1
#define SOIL_DAY_LOWS                GRF + 3677            // 24 ||  1
#define SOIL_DAY_LOW_TIMES           GRF + 3701            // 24 ||  2
#define SOIL_DAY_HIGHS               GRF + 3749            // 24 ||  1
#define SOIL_DAY_HIGH_TIMES          GRF + 3773            // 24 ||  2
#define SOIL_MONTH_LOWS              GRF + 3821            // 25 ||  1
#define SOIL_MONTH_HIGHS             GRF + 3846            // 25 ||  1
#define SOIL_YEAR_LOWS               GRF + 3871            //  1 ||  1
#define SOIL_YEAR_HIGHS              GRF + 3872            //  1 ||  1
#define SOIL_YEAR_HIGHS_COMP         GRF + 3873            //  1 ||  1

#define RX_PERCENTAGE                GRF + 3874            //  24 ||  1

#define SAVE_MIN                     RX_PERCENTAGE+25 = 4084
#define SAVE_HOUR                    SAVE_MIN+1
#define SAVE_DAY                     SAVE_HOUR+1
#define SAVE_MONTH                   SAVE_HOUR+2
#define SAVE_YEAR                    SAVE_HOUR+3
#define SAVE_YEAR_COMP               SAVE_HOUR+4
#define BAUD_RATE                    SAVE_HOUR+5
#define DEFAULT_RATE_GRAPH           SAVE_HOUR+6
	
	
/* Definition of Davis LOOP data packet */
typedef struct t_RTDATA
{
	BYTE	yACK;			/* -1 ACK from stream							*/
	char	cL;				/* 0  character "L"								*/
	char	cO;				/* 1  character "O"								*/
	char	cO1;			/* 2  character "O"								*/
	char	cP;				/* 3  character "P" (RevA) or the current		*/
							/*    3-hour Barometer trend as follows: 		*/
							/*    196 = Falling Rapidly						*/
							/*    236 = Falling Slowly						*/
							/*    0   = Steady								*/
							/*    20  = Rising Slowly						*/
							/*    60  = Rising Rapidly						*/
							/* any other value is 3-hour data not available */
	BYTE	yPacketType;	/* 4 Always zero for current firmware release	*/
	WORD	wNextRec;		/* 5 loc in archive memory for next data packet	*/
	WORD	wBarometer;		/* 7 Current barometer as (Hg / 1000)			*/
	WORD	wInsideTemp;	/* 9 Inside Temperature as (DegF / 10)			*/
	BYTE	yInsideHum;		/* 11 Inside Humidity as percentage				*/
	WORD	wOutsideTemp;	/* 12 Outside Temperature as (DegF / 10)		*/
	BYTE	yWindSpeed;		/* 14 Wind Speed								*/
	BYTE	yAvgWindSpeed;	/* 15 10-Minute Average Wind Speed				*/
	WORD	wWindDir;		/* 16 Wind Direction in degress					*/
	BYTE	yXtraTemps[7];	/* 18 Extra Temperatures						*/
	BYTE	ySoilTemps[4];	/* 25 Soil Temperatures							*/
	BYTE	yLeafTemps[4];	/* 29 Leaf Temperatures							*/
	BYTE	yOutsideHum;	/* 33 Outside Humidity							*/
	BYTE	yXtraHums[7];	/* 34 Extra Humidities							*/
	WORD	wRainRate;		/* 41 Rain Rate									*/
	BYTE	yUVLevel;		/* 43 UV Level									*/
	WORD	wSolarRad;		/* 44 Solar Radiation							*/
	WORD	wStormRain;		/* 46 Total Storm Rain							*/
	WORD	wStormStart;	/* 48 Start date of current storm				*/
	WORD	wRainDay;		/* 50 Rain Today								*/
	WORD	wRainMonth;		/* 52 Rain this Month							*/
	WORD	wRainYear;		/* 54 Rain this Year							*/
	WORD	wETDay;			/* 56 Day ET									*/
	WORD	wETMonth;		/* 58 Month ET									*/
	WORD	wETYear;		/* 60 Year ET									*/
	DWORD	wSoilMoist;		/* 62 Soil Moistures							*/
	DWORD	wLeafWet;		/* 66 Leaf Wetness								*/
	BYTE	yAlarmInside;	/* 70 Inside Alarm bits							*/
	BYTE	yAlarmRain;		/* 71 Rain Alarm bits							*/
	WORD	yAlarmOut;		/* 72 Outside Temperature Alarm bits			*/
	BYTE	yAlarmXtra[8];	/* 74 Extra Temp/Hum Alarms						*/
	DWORD	yAlarmSL;		/* 82 Soil and Leaf Alarms						*/
	BYTE	yXmitBatt;		/* 86 Transmitter battery status				*/
	WORD	wBattLevel;		/* 87 Console Battery Level:					*/
							/*    Voltage = ((wBattLevel * 300)/512)/100.0	*/
	BYTE	yForeIcon;		/* 89 Forecast Icon								*/
	BYTE	yRule;			/* 90 Forecast rule number						*/
	WORD	wSunrise;		/* 91 Sunrise time (BCD encoded, 24hr)			*/
	WORD	wSunset;		/* 93 Sunset time  (BCD encoded, 24hr)			*/
	BYTE	yLF;			/* 95 Line Feed (\n) 0x0a						*/
	BYTE	yCR;			/* 96 Carraige Return (\r) 0x0d					*/
	WORD	WCRC;			/* 97 CRC check bytes (CCITT-16 standard)		*/
} RTDATA;	


/* Definition of Davis HILOW packet */
typedef struct t_HLDATA
{
	BYTE	yACK;			/* -1 ACK from stream							*/
	
	/* barometer */
	WORD	wBaroLoDay;		/* 0  Low barometer for today					*/
	WORD	wBaroHiDay;		/* 2  High barometer for today					*/
	WORD	wBaroLoMonth;	/* 4  Low barometer this month					*/
	WORD	wBaroHiMonth;	/* 6  High barometer this month					*/
	WORD	wBaroLoYear;	/* 8  Low barometer this year					*/
	WORD	wBaroHiYear;	/* 10 High barometer this year					*/
	WORD	wBaroLoTime;	/* 12 Low barometer time of day					*/
	WORD	wBaroHiTime;	/* 14 High barometer time of day				*/
	
	/* wind speed */
	BYTE	yWindHiDay;		/* 16 Highest wind speed for today				*/
	WORD	wWindHiTime;	/* 18 Highest wind speed time of day			*/
	BYTE	yWindHiMonth;	/* 18 Highest wind speed for the month			*/
	BYTE	yWindHiYear;	/* 20 Highest wind speed for the year			*/
	
	/* inside temperatures */
	WORD	wInTempHiDay;	/* 21 Inside high temp for today				*/
	WORD	wInTempLoDay;	/* 23 Inside low temp for today					*/
	WORD	wInTempHiTime;	/* 25 Time of Inside high temp for today		*/
	WORD	wInTempLoTime;	/* 27 Time of Inside low temp for today			*/
	WORD	wInTempLoMonth;	/* 29 Inside low temp for the month				*/
	WORD	wInTempHiMonth;	/* 31 Inside high temp for the month			*/
	WORD	wInTempLoYear;	/* 33 Inside low temp for the year				*/
	WORD	wInTempHiYear;	/* 35 Inside high temp for the year				*/
	
	/* Inside Humidity */
	BYTE	yInHumHiDay;	/* 37 Inside high humidity for the day			*/
	BYTE	yInHumLoDay;	/* 38 Inside low humidity for the day			*/
	WORD	wInHumHiTime;	/* 39 Inside high humidity time for today		*/
	WORD	wInHumLoTime;	/* 41 Inside low humidity time for today		*/
	BYTE	yInHumHiMonth;	/* 43 Inside high humidity for the month		*/
	BYTE	yInHumLoMonth;	/* 44 Inside low humidity for the month			*/
	BYTE	yInHumHiYear;	/* 45 Inside high humidity for the year			*/
	BYTE	yInHumLoYear;	/* 46 Inside low humidity for the year			*/
	
	/* outside temperatures */
	WORD	wTempLoDay;		/* 49 Outside low temp for today				*/
	WORD	wTempHiDay;		/* 47 Outside high temp for today				*/
	WORD	wTempLoTime;	/* 53 Time of Outside low temp for today		*/
	WORD	wTempHiTime;	/* 51 Time of Outside high temp for today		*/
	WORD	wTempHiMonth;	/* 57 Outside high temp for the month			*/
	WORD	wTempLoMonth;	/* 55 Outside low temp for the month			*/
	WORD	wTempHiYear;	/* 61 Outside high temp for the year			*/
	WORD	wTempLoYear;	/* 59 Outside low temp for the year				*/

	/* dew point */
	WORD	wDewLoDay;		/* 63 dew point low for today					*/
	WORD	wDewHiDay;		/* 65 dew point high for today					*/
	WORD	wDewLoTime;		/* 67 Time of dew point low for today			*/
	WORD	wDewHiTime;		/* 69 Time of dew point high for today			*/
	WORD	wDewHiMonth;	/* 71 Highest dew point this month				*/
	WORD	wDewLoMonth;	/* 73 Lowest dew point this month				*/
	WORD	wDewHiYear;		/* 75 Highest dew point for the year			*/
	WORD	wDewLoYear;		/* 77 Lowest dew point for the year				*/
	
	/* wind chill */
	WORD	wChillLoDay;	/* 79 wind chill low for today					*/
	WORD	wChillLoTime;	/* 81 Time of wind chill low for today			*/
	WORD	wChillLoMonth;	/* 83 Lowest wind chill this month				*/
	WORD	wChillLoYear;	/* 85 Lowest wind chill for the year			*/
	
	/* heat indices */
	WORD	wHeatHiDay;		/* 87 Heat index high for today					*/
	WORD	wHeatHiTime;	/* 89 Time of heat index high for today			*/
	WORD	wHeatHiMonth;	/* 91 Heat index high for the month				*/
	WORD	wHeatHiYear;	/* 93 Heat index high for the year				*/
	
	/* THSW indices */
	WORD	wTHSWHiDay;		/* 95 THSW index high for today					*/
	WORD	wTHSWHiTime;	/* 97 Time of THSW index high for today			*/
	WORD	wTHSWHiMonth;	/* 99 THSW index high for the month				*/
	WORD	wTHSWHiYear;	/* 101 THSW index high for the year				*/

	/* Solar Radiation */
	WORD	wSolarHiDay;	/* 103 Solar rad high for today					*/
	WORD	wSolarHiTime;	/* 105 Time of Solar rad high for today			*/
	WORD	wSolarHiMonth;	/* 107 Solar rad high for the month				*/
	WORD	wSolarHiYear;	/* 109 Solar rad high for the year				*/

	/* UV Index */
	BYTE	yUVHiDay;		/* 111 UV high for today						*/
	WORD	wUVHiTime;		/* 112 Time of UV high for today				*/
	BYTE	yUVHiMonth;		/* 114 UV high for the month					*/
	BYTE	yUVHiYear;		/* 115 UV high for the year						*/

	/* Rain Rate */
	WORD	wRainHiDay;		/* 116 Rain Rate high for today					*/
	WORD	wRainHiTime;	/* 118 Time of Rain Rate high for today			*/
	WORD	wRainHiHour;	/* 120 Highest Rain Rate this hour				*/
	WORD	wRainHiMonth;	/* 122 Highest Rain Rate this month				*/
	WORD	wRainHiYear;	/* 124 Highest Rain Rate this year				*/
	
	BYTE	yExtraLeaf[150];/* 126 Extra/Leaf/Soil Temperatures				*/	
	BYTE	yExtraTemps[80];/* 276 Extra outside temp/Humidities			*/	
	BYTE	ySoilMoist[40];	/* 356 Soil Moisture section					*/	
	BYTE	yLeafWet[40];	/* 396 Leaf Wetness section						*/
	WORD	wUnknown;		/* 436 not documented							*/
	WORD	WCRC;			/* 438 CRC check bytes (CCITT-16 standard)		*/
} HLDATA;

/* Definition of Davis EEPROM data packet */
typedef struct t_EEDATA
{
	BYTE	szDumm[177];	/* stuff not used in this version		*/
	
} EEDATA;


#ifdef __cplusplus
}
#endif /* __cplusplus	 */
#endif /* __DHANDLER_H__ */
