#!/usr/bin/env python3

import argparse
import os
import re
import shutil
import subprocess
import sys
import time
import tempfile

params = {'port':9100,'host':'localhost'}

if 'DAVIS_HOSTNAME' in os.environ.keys():
    params['host'] = os.environ['DAVIS_HOSTNAME']

if 'DAVIS_PORT' in os.environ.keys():
    params['port'] = os.environ['DAVIS_PORT']

def validate_externals(path=None):
    tools = []
    tools.append(shutil.which('remserial'))
    tools.append(shutil.which('vproweather'))
    if None in tools:
        raise OSError('External tools not in PATH. Check.')

def append_externals_to_path():
    env = os.environ
    current_script = os.path.abspath(__file__)
    current_directory = os.path.dirname(current_script)
    external_dir = current_directory + '/../external'

    # 3 lines below specify seprate dirs
    #remserial_dir = external_dir+'/remserial-1.3'
    #vproweather_dir = external_dir+'/vproweather-0.6'
    #env['PATH'] = remserial_dir+':'+vproweather_dir+':'+env['PATH']

    # This corresponds to unified external dir from setup.py
    env['PATH'] = external_dir+':'+env['PATH']

    return env

def establish_connection(params):
    tempname = next(tempfile._get_candidate_names())
    device_link = "/tmp/"+tempname
    connection = subprocess.Popen(["remserial","-d","-r",str(params['host']),\
        "-p",str(params['port']),"-l",device_link,"/dev/ptmx"],\
        stdout=subprocess.PIPE,stderr=subprocess.STDOUT)
    time.sleep(2)
    return connection, device_link

class realTimeOutput:
    '''
    rtBaroCurr
    rtBaroTrend
    rtBaroTrendImg
    rtBattVoltage
    rtDayET
    rtDayRain
    rtForeIcon
    rtForeRule
    rtForecast
    rtInsideHum
    rtInsideTemp
    rtIsRaining
    rtMonthET
    rtMonthRain
    rtOutsideHum
    rtOutsideTemp
    rtRainRate
    rtRainStorm
    rtSolarRad
    rtStormStartDate
    rtSunrise
    rtSunset
    rtUVLevel
    rtWindAvgSpeed
    rtWindDir
    rtWindDirRose
    rtWindSpeed
    rtXmitBattt
    rtYearRain
    '''
    def __init__(self,stdout):
        stdout = stdout.decode('utf-8')
        stdout = stdout.split('\n')
        stdout = [x for x in stdout if x != '']
        result = {}
        regex=re.compile('^[0-9][0-9]-[A-Z]')
        for x in stdout:
            k,v = x.split(' = ')
            if 'n/a' in v:
                v = None
            elif ('AM' in v) or ('PM' in v):
                v = str(v)
            elif re.match(regex, v):
                v = str(v)
            elif v == 'no':
                v = False
            elif v == 'yes':
                v = True
            elif v[0].isdigit():
                v = float(v)
            result[k] = v
        self.__dict__ = result


def call_vproweather(device,opt='-x'):
    cmd = 'vproweather -x '+device
    proc = subprocess.Popen(cmd.split(' '),stdout=subprocess.PIPE,stderr=subprocess.STDOUT)
    stdout, stderr = proc.communicate()
    proc.terminate()
    time.sleep(1)
    return stdout, proc.returncode


def current():
    env = append_externals_to_path()
    validate_externals(path=env['PATH'])
    connection, device = establish_connection(params)
    stdout, rc = call_vproweather(device)
    connection.terminate()
    return realTimeOutput(stdout)

if __name__ == '__main__':
    C = current()
    print('Current Temperature: '+str(C.rtOutsideTemp))
    exit(0)

