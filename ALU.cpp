#include "ALU.h"

#include <bitset>
#include <math.h>

ALU::ALU() { }

void ALU::performOperation() {

	// Add : add, addi
	if (operation.compare("add") == 0) {
		result = add(input_1, input_2);
	}

	// Subtract : sub
	else if (operation.compare("sub") == 0) {
		result = subtract(input_1, input_2);
	}

	// Compare : beq
	else if (operation.compare("compare") == 0) {
		result = compare(input_1, input_2); 
	}
	else if (operation.compare("lessThan") == 0) {
		result = lessThan(input_1, input_2);
	}

}

	// Adds input1 and input2 (binary numbers represented as strings) and returns the result
	// @param 	input1 	one of two operands being summed
	// @param	input2 	one of two operands being summed
	// @return 	string representation of input1 + input2
string ALU::add(string input1, string input2) {
	
	double input1_dec = binaryToDecimal(input1);
	double input2_dec = binaryToDecimal(input2);

	double sum_dec = input1_dec + input2_dec;

	string sum_bin = decimalToBinary(sum_dec);

	return sum_bin;
}

	// Subtracts input2 from input1 (binary numbers represented as strings) and returns the result
	// @param 	input1 	input to subtract from
	// @param	input2 	input subtracted from input1
	// @return 	string representation of input1 - input2
string ALU::subtract(string input1, string input2) {

	double input1_dec = binaryToDecimal(input1);
	double input2_dec = binaryToDecimal(input2);

	double diff_dec = input1_dec - input2_dec;

	string diff_bin = decimalToBinary(diff_dec);

	return diff_bin;
}

	// Returns "equal" if input1 and input2 are equivalent, "not_equal" otherwise
	// @param 	input1 	one of two operands being tested for equivalency 
	// @param	input2 	one of two operands being tested for equivalency 
	// @return 	"equal" if input1 and input2 are equivalent, "not_equal" if not
string ALU::compare(string input1, string input2) {
	double input1_dec = binaryToDecimal(input1);
	double input2_dec = binaryToDecimal(input2);

	bool equals = (input1_dec == input2_dec);

	if (equals) {
		return "equal";
	}
	return "not_equal";
}

	// Returns "00000000000000000000000000000001" if input1 is less than input2, "00000000000000000000000000000000" if otherwise
	// @param	input1 	input being tested if it is less than input2
	// @param	input2 	input that is being tested against, to see if input1 is smaller
	// @return 	"00000000000000000000000000000001" if input1 is less than input2, "00000000000000000000000000000000" if not
string ALU::lessThan(string input1, string input2) {
	double input1_dec = binaryToDecimal(input1);
	double input2_dec = binaryToDecimal(input2);

	double diff_dec = input1_dec - input2_dec;
	// If difference is negative, input1 < input2, return 1
	if (diff_dec < 0) { 
		return "00000000000000000000000000000001";
	}
	// Otherwise, return 0
	else {
		return "00000000000000000000000000000000";
	}
}

	// Converts 32-bit binary string input to its decimal value
	// @param 	input 	32-bit binary string input to convert
	// @return 	double decimal representation of given input
double ALU::binaryToDecimal(string input) {

	double decimal = 0.0;
	int power = 0;

	// For each char in the given 32-bit input
	for(int i = input.length() - 1; i >= 0; i--) {
		
		if (input.at(i) == '1') {
			decimal += pow(2.0, power);
		}
		power++;
	}

	return decimal;
}

	// Converts decimal input to its 32-bit binary string 
	// @param 	input 	decimal input to convert
	// @return 	string 32-bit binary representation of given input
string ALU::decimalToBinary(double value) { 
	bitset<32> bits = value;
	return bits.to_string();
}
