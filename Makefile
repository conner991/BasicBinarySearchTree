# ----------------------------------------------------------------------------------------
# FILE NAME:	Makefile
# 
# DESCRIPTION: 	Makefile for a C++ Program
#
# PURPOSE:		Build a program executable on Linux
# 
# MODIFICATION HISTORY: 
#
# Author		 		   Date				Modifications(s)
# ---------		 		----------			------------------
# Conner Fissell		09-18-2019			Version 1
# Conner Fissell		09-23-2019			Version 2 - Modified for .h files
# Conner Fissell		02-08-2020			Version 3 - Modified for CS302 HW 1
# ________________________________________________________________________________________

#	This is our original generic makefile command that will build
#	any stand alone ".cpp" source file
#	Usage: e.g. make hello
.cpp:
	g++ -o $* $*.cpp -std=c++11