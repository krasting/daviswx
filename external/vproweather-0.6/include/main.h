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
/* main.h.h - main header file												*/
/* tabs every 4 places														*/
/*																			*/
/****************************************************************************/

#ifndef __MAIN_H__
#define __MAIN_H__

#ifdef __cplusplus
#define extern "C" {		/* respect c++ callers */
#endif

typedef int BOOL;			/* yet another bool definition */
#define TRUE 1
#define FALSE 0

typedef unsigned char BYTE;
typedef unsigned short WORD;	
typedef unsigned long DWORD;	

#define LOBYTE(w)	((BYTE)(w))
#define HIBYTE(w)	((BYTE)(((WORD)(w) >> (BYTE)8) & 0xff))


#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* __MAIN_H__ */
