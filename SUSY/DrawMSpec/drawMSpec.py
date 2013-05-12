#!/usr/bin/env python 
# Code to draw mass spectrum from slha input file
# Author : Martin Tripiana <tripiana@cern.ch>

import sys, os, string, math
import argparse

def error(self, message):
    """error(message: string)

    Prints a usage message incorporating the message to stderr and
    exits.

    If you override this in a subclass, it should not return -- it
    should either exit or raise an exception.
    """
    self.print_usage(sys.stderr)
    self.exit(2, '%s: error: %s\n' % (self.prog, message))
	  
parser = argparse.ArgumentParser(description='input options handler')

parser.add_argument('ifile', metavar='INFILE', nargs='?', help='slha formatted file to be read')
parser.add_argument('-t', action='store', dest='tag', default='', help='tag for output image')
parser.add_argument('-m', action='store', dest='min', default='-1', help='minimum mass value [GeV]')
parser.add_argument('-x', action='store', dest='max', default='-1', help='maximum mass value [GeV]')
parser.add_argument('-f', action='store', dest='format', default='eps', help='output graphic format : eps (default),png, pdf, ...)')

config = parser.parse_args()
if config.ifile is None:
	parser.print_help()
	sys.exit(1)
	
IFILE = config.ifile
TAG = str(config.tag)
MIN = float(config.min)
MAX = float(config.max)
		
if not os.path.exists(IFILE):
    print "\nFile \'"+IFILE+"\' seems not to exist. Please check and come back...\n"
    sys.exit(1)
		
#if not os.path.exists(IFILE):
#    print "\nThis file doesn't exist!! Please check and come back..."
#    sys.exit(1)

#Load input file
spectrum = file(IFILE)

#define tag (if required
if not TAG == '':
    if not TAG.startswith('_'):
	tmp = "\'"+"_"+TAG+"\'"
	TAG = tmp	
	
### Get mass of susy particles
#Neutralinos
M_chi10=-9999
M_chi20=-9999
M_chi30=-9999
M_chi40=-9999

#Charginos
M_chi1p=-9999
M_chi2p=-9999

#Squarks
M_uL=-9999
M_uR=-9999
M_dL=-9999
M_dR=-9999
M_sL=-9999
M_sR=-9999
M_cL=-9999
M_cR=-9999
M_t1=-9999
M_t2=-9999
M_b1=-9999
M_b2=-9999


#Sleptons
M_eL=-9999
M_eR=-9999
M_nu_eL=-9999 
M_muL=-9999
M_muR=-9999
M_nu_muL=-9999 
M_tau1=-9999
M_tau2=-9999
M_nu_tauL=-9999

#Higgses
M_h0=-9999
M_H=-9999
M_Hp=-9999
M_A=-9999

#gluino
M_gl=-9999

#gravitino
M_G=-9999

def findMax(lst):
    max=0
    for item in lst:
        if float(item)>max:
            max=float(item)
    return max

def findMin(lst):
    min=9999999
    for item in lst:
        if float(item)<min:
            min=float(item)
    return min

def formatLine(line):
    line.replace(" ","$")    
    sl=''
    add = False
    for ch in line:
        if ch == "$":
            add = True
            continue
        else:
            if add == True:
                sl = sl+" "+ch
                add = False
    return sl

#Extract masses from file
mlist=[]
for line in spectrum:
    fields = line.split()
    if "decays" in line: #to avoid overwritten values
        continue

    if "# ~chi_10" in line: 
        M_chi10 = math.fabs(float(fields[1]))
        mlist.append(M_chi10)
        continue
    if "# ~chi_20" in line: 
        M_chi20 = math.fabs(float(fields[1]))
        mlist.append(M_chi20)	
        continue
    if "# ~chi_30" in line: 
        M_chi30 = math.fabs(float(fields[1]))
        mlist.append(M_chi30)	
        continue
    if "# ~chi_40" in line: 
        M_chi40 = math.fabs(float(fields[1]))
        mlist.append(M_chi40)	
        continue
    if "# ~chi_1+" in line: 
        M_chi1p = math.fabs(float(fields[1]))
        mlist.append(M_chi1p)	
        continue
    if "# ~chi_2+" in line: 
        M_chi2p = math.fabs(float(fields[1]))
        mlist.append(M_chi2p)	
        continue
    if "# ~u_L" in line: 
        M_uL = math.fabs(float(fields[1]))
        mlist.append(M_uL)	
        continue
    if "# ~u_R" in line: 
        M_uR = math.fabs(float(fields[1]))
        mlist.append(M_uR)	
        continue
    if "# ~d_L" in line: 
        M_dL = math.fabs(float(fields[1]))
        mlist.append(M_dL)	
        continue
    if "# ~d_R" in line: 
        M_dR = math.fabs(float(fields[1]))
        mlist.append(M_dR)	
        continue
    if "# ~s_L" in line: 
        M_sL = math.fabs(float(fields[1]))
        mlist.append(M_sL)	
        continue
    if "# ~s_R" in line: 
        M_sR = math.fabs(float(fields[1]))
        mlist.append(M_sR)	
        continue
    if "# ~c_L" in line: 
        M_cL = math.fabs(float(fields[1]))
        mlist.append(M_cL)	
        continue
    if "# ~c_R" in line: 
        M_cR = math.fabs(float(fields[1]))
        mlist.append(M_cR)	
        continue
    if "# ~t_1" in line: 
        M_t1 = math.fabs(float(fields[1]))
        mlist.append(M_t1)	
        continue
    if "# ~t_2" in line: 
        M_t2 = math.fabs(float(fields[1]))
        mlist.append(M_t2)	
        continue
    if "# ~b_1" in line: 
        M_b1 = math.fabs(float(fields[1]))
        mlist.append(M_b1)	
        continue
    if "# ~b_2" in line: 
        M_b2 = math.fabs(float(fields[1]))
        mlist.append(M_b2)	
        continue
    if "# ~e_L" in line: 
        M_eL = math.fabs(float(fields[1]))
        mlist.append(M_eL)	
        continue
    if "# ~e_R" in line: 
        M_eR = math.fabs(float(fields[1]))
        mlist.append(M_eR)	
        continue
    if "# ~nu_eL" in line: 
        M_nu_eL = math.fabs(float(fields[1]))
        mlist.append(M_nu_eL)	
        continue
    if "# ~mu_L" in line: 
        M_muL = math.fabs(float(fields[1]))
        mlist.append(M_muL)	
        continue
    if "# ~mu_R" in line: 
        M_muR = math.fabs(float(fields[1]))
        mlist.append(M_muR)	
        continue
    if "# ~nu_muL" in line: 
        M_nu_muL = math.fabs(float(fields[1]))
        mlist.append(M_nu_muL)
        continue
    if "# ~tau_1" in line: 
        M_tau1 = math.fabs(float(fields[1]))
        mlist.append(M_tau1)	
        continue
    if "# ~tau_2" in line: 
        M_tau2 = math.fabs(float(fields[1]))
        mlist.append(M_tau2)	
        continue
    if "# ~nu_tauL" in line: 
        M_nu_tauL = math.fabs(float(fields[1]))
        mlist.append(M_nu_tauL)	
        continue
    if "# h" in line and fields[0]=="25":
        M_h0 = math.fabs(float(fields[1]))
        mlist.append(M_h0)	
        continue
    if "# H" in line and fields[0]=="35":
        M_H = math.fabs(float(fields[1]))
        mlist.append(M_H)	
        continue
    if "# H+" in line and fields[0]=="37":
        M_Hp = math.fabs(float(fields[1]))
        mlist.append(M_Hp)	
        continue
    if "# A" in line and fields[0]=="36":
        M_A = math.fabs(float(fields[1]))
        mlist.append(M_A)	
        continue
    if "# ~g" in line and fields[0]=="1000021":
        M_gl = math.fabs(float(fields[1]))
        mlist.append(M_gl)	
        continue
    if "# ~gravitino" in line: 
        M_G = math.fabs(float(fields[1]))
        mlist.append(M_G)
        continue

if MAX < 0:
    MAX=findMax(mlist)*10.

if MIN < 0:
    MIN=findMin(mlist)/10.


#Call Drawing code for read spectrum
MACRO_CALL="\'"+"DrawMassSpectrum.C("+str(M_chi10)+","+str(M_chi20)+","+str(M_chi30)+","+str(M_chi40)+","+str(M_chi1p)+","+str(M_chi2p)+","+str(M_uL)+","+str(M_uR)+","+str(M_dL)+","+str(M_dR)+","+str(M_sL)+","+str(M_sR)+","+str(M_cL)+","+str(M_cR)+","+str(M_t1)+","+str(M_t2)+","+str(M_b1)+","+str(M_b2)+","+str(M_eL)+","+str(M_eR)+","+str(M_nu_eL)+","+str(M_muL)+","+str(M_muR)+","+str(M_nu_muL)+","+str(M_tau1)+","+str(M_tau2)+","+str(M_nu_tauL)+","+str(M_h0)+","+str(M_H)+","+str(M_Hp)+","+str(M_A)+","+str(M_gl)+","+str(M_G)+","+str(MIN)+","+str(MAX)+",\""+TAG+"\",\""+config.format+"\")"+"\'"

os.system("root -l -b -q "+MACRO_CALL)

