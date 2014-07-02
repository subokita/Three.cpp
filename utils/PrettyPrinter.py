#!/usr/local/Cellar/python/2.7.6/bin/python
# -*- coding: utf-8 -*-

import sys
import string


filename = "pretty_printer_input.txt"

def main():
	# alignEqualSign()
	text, max_len, max_var_len = extractVariableNames()

	class_name = 'ParticleSystemMaterial'
	base_class_name = 'Material'

	# generateSomeBoilerplates( class_name )
	# alignVariables( text, max_len, max_var_len )
	# generatePrintStatement( text, max_len, max_var_len, class_name )
	createInitializerList( text, max_len, max_var_len, False, base_class_name )
	createInitializerList( text, max_len, max_var_len, True, base_class_name )
	

	pass


 # Generate some codes for the constructors in header file
 # Use this if you got tired typing constructors
def generateSomeBoilerplates( class_name ):
	print "/** Constructors **/"
	print class_name + "();"
	print class_name + "( const " + class_name + "& rhs );"
	print class_name + " clone();"
	print "~" + class_name + "();"
	print ""


 # Align all the assigment statements, so that
 # we have perfectly aligned equal signs
def alignEqualSign() :
	text = {}

	counter = 0
	text[counter] = list()
	
	with open( filename, 'r' ) as f:
		lines = f.readlines()

		for line in lines:
			line = line.strip()
			if( len( line ) == 0 ):
				continue

			if "=" not in line:
				counter += 1
				text[counter] = list()
				text[counter].append( line )
			else:
				if( type( text[counter] ) is not list ):
					text[counter] = list()
				text[counter].append( line )
			
	for entry in text:
		
		max_index = -1;
		for line in text[entry]:
			index = line.find('=')
			if max_index < index:
				max_index = index

		for line in text[entry]:
			index = line.find('=')
			if( index > -1 ):
				print line[:index].ljust( max_index ) + '=' + line[index+1:]
			else:
				print '\n' + line


 # Extract the variable names from the Input.txt file
 # it also returns the max length of the variable names, and
 # max length of the type name
def extractVariableNames() :
	text = []

	with open( filename, 'r' ) as f:
		lines = f.readlines()

		for line in lines:
			line = line.strip()
			if( len( line ) == 0 ):
				continue

			index = line.find(' ')

			text.append( (line[ :index ].strip(), line[ index+1: len(line) - 1 ].strip()) )


	max_var_len = 0
	max_len = 0
	for t, var in text:
		if len(var) > max_len:
			max_len = len(var)
		if len(t) > max_var_len:
			max_var_len = len( t )

	return (text, max_len, max_var_len)


 # Create an initializer list statement
 # in pretty printed manner
def createInitializerList( text, max_len, max_var_len, rhs = False, parent = '' ) :
	print ':'

	if rhs is True:
		if len( parent ) != 0:
			print parent.ljust(max_len) + '( rhs ),'

		for i in range( 0, len(text) - 1 ):
			print text[i][1].ljust(max_len) + '( rhs.' + text[i][1] + ' ),'	
		print text[-1][1].ljust(max_len) + '( rhs.' + text[-1][1] + ' )'	
	else:
		for i in range( 0, len(text) - 1 ):
			print text[i][1].ljust(max_len) + '(),'	
		print text[-1][1].ljust(max_len) + '()'	
	print ""

 # Generate stream overloading statement
 # for printing purposes
def generatePrintStatement( text, max_len, max_var_len, class_name ):
	print '/** Output stream overloading */'
	print 'friend std::ostream &operator <<( std::ostream& os, const ' + class_name + '& obj ) {'

	print '\tos << "' + class_name + ' {" << std::endl;'

	for t, var in text:
		if t.startswith('glm'):
			print '\tos << "\\t' + var.ljust( max_len ) + ': " << Utils::toString( obj.' + var + ' ) << std::endl;'
		else:
			print '\tos << "\\t' + var.ljust( max_len ) + ': " << obj.' + var.ljust( max_len ) + ' << std::endl;'

	print '\tos << "}";'
	print '\treturn os;'
	print '}\n'

 # Align the data members of the class
 # so that they looks organized
def alignVariables( text, max_len, max_var_len ):
	print '/* Data members */'
	for t, var in text:
		print t.ljust( max_var_len ) + ' ' + var + ';'
	print '\n'




if __name__ == '__main__':
	main()