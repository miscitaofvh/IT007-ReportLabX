#!/bin/bash

grade=$1

if [ $grade -lt 500 ]; then
	echo "Your letter grade is D"
elif [ $grade -lt 600 ]; then 
	echo "Your letter grade is C"
elif [ $grade -lt 700 ]; then
	echo "Your letter grade is B"
elif [ $grade -lt 800 ]; then 
	echo "Your letter grade is B+"
elif [ $grade -lt 900 ]; then 
	echo "Your letter grade is A"
else 
	echo "Your letter grade is A+"	

fi
