import time
import subprocess
import psutil
from tabulate import tabulate

My_Vector = "./tests/vector_tests/MY_VEC"
Original_Vector = "./tests/vector_tests/ORG_VEC"

# My_Map = "./tests/map_tests/MY_MAP"
# Original_Map = "./tests/map_tests/ORG_MAP"
#
# My_Stack = "./tests/stack_tests/MY_STACK"
# Original_Stack = "./tests/stack_tests/ORG_STACK"

"""
This script defines a function called compare_executables() which takes the file paths 
of the two executables to be compared as its parameters. 

Inside the function, the script first measures the time and resources used by each executable using 
the time and psutil libraries as before. 
Then, it runs the two executables and captures their output using the subprocess.run() function, 
and compares the output using an if statement. 
If the output is different, it prints the output of each executable. 
Finally, it prepares the data for tabulation and prints the results in a table using the tabulate library.

You can call this function and pass the paths of the two executables to be compared as 
its parameters to get the comparison result with time and resources used by each executable.

Note that this script can also be improved to measure other resources like CPU usage, etc. 
and also by adding more attributes of the subprocess.CompletedProcess object in the comparison.
"""


def compare_executables(file1, file2):
	"""
	This function compares the results of two executables and shows the difference.
	It also measures the time and resources used by the executables.

	Parameters:
		file1 (str): The path to the first executable.
		file2 (str): The path to the second executable.

	Returns:
		None
	"""
	# Measure time and resources used by first executable
	start_time = time.time()
	p1 = psutil.Popen(file1, shell=True)
	mem_info1 = p1.memory_info()
	p1.wait()
	end_time = time.time()
	time_used1 = end_time - start_time

	# Measure time and resources used by second executable
	start_time = time.time()
	p2 = psutil.Popen(file2, shell=True)
	mem_info2 = p2.memory_info()
	p2.wait()
	end_time = time.time()
	time_used2 = end_time - start_time

	# Run the first executable and capture its output
	result1 = subprocess.run(file1, capture_output=True, text=True)

	# Run the second executable and capture its output
	result2 = subprocess.run(file2, capture_output=True, text=True)

	# Compare the output of the two executables
	if result1.stdout == result2.stdout:
		print("The output of the two executables is the same.")
	else:
		print("Output of executable 1:")
		print(result1.stdout)
		print("Output of executable 2:")
		print(result2.stdout)
		print("\033[1;31;40m ❌❌ The outputs for [MY_VEC], [ORG_VEC] are different.\033[0m")

	# To convert bytes to megabytes, divide by 1024 ** 2.
	# To convert bytes to kilobytes, divide by 1024.
	# Prepare data for tabulation converts bytes to kb
	data = [
		[My_Vector, time_used1, mem_info1.rss / 1024],
		[Original_Vector, time_used2, mem_info2.rss / 1024]
	]
	headers = ["Executable", "Time (s)", "Memory (KB)"]

	# Print the results in a table
	print(tabulate(data, headers, tablefmt="fancy_grid"))


# Call the function to compare the executables
if __name__ == '__main__':
	flag = input("""
	>>>  Welcome to Gab test script:
		─➤  1- Test vector --> press[1]
		─➤  2- Test map	   --> press[2]
		─➤  3- Test stack  --> press[3]
	
	>>>  """)
	while flag != '1' and flag != '2' and flag != '3':
		flag = input("Invalid input. Please enter a valid input: ")
	if flag == '1':
		compare_executables(My_Vector, Original_Vector)
	# elif flag == '2':
	# 	compare_executables(My_Map, Original_Map)
	# elif flag == '3':
	# 	compare_executables(My_Stack, Original_Stack)
