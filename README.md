NeoQtTestDemo
=============

A collection of Qt Demos, each Test some aspect of some Qt Controls or Classes 

Sub Projects
-------------
1. **TQLineEdit\_ContentControl**

	A demo for testing the combination of setValidator and setInputMask functions,
	notice that the validator used is QRegExpValidator and should be guaranteed by
	the user; example is : 
	
	```(?:[_\dA-Fa-f]{2})(?::[_\dA-Fa-f]{2}){0,3} ```
	
	which accept the format of 1 to 4 groups of Hex numbers, seperated by ':', eg: ```12:AB:FF:0``` 
	
2. **Coming later**
