// Java program to check if String contains only Alphabets
// Using Lambda Expression

class lamda {

	// Method 1
	// To check String for only Alphabets
	public static boolean isStringOnlyAlphabet(String str)
	{
		return (
			(str != null) && (!str.equals(""))
			&& (str.chars().allMatch(Character::isLetter)));
	}

	// Method 2
	// Main driver method
	public static void main(String[] args)
	{

		// Calling method over different strings
		// justifying all use-cases possible

		// Display message
		System.out.println("Test Case 1:");

		String str1 = "GeeksforGeeks";
		System.out.println("Input: " + str1);

		// Calling over above string: GeeksforGeeks
		System.out.println("Output: "
						+ isStringOnlyAlphabet(str1));

		// Checking for String with numeric characters
		System.out.println("\nTest Case 2:");

		String str2 = "Geeks4Geeks";
		System.out.println("Input: " + str2);

		// Calling over above string: Geeks4Geeks
		System.out.println("Output: "
						+ isStringOnlyAlphabet(str2));

		// Checking for null String
		System.out.println("\nTest Case 3:");
		String str3 = null;
		System.out.println("Input: " + str3);

		// Calling over above string: null
		System.out.println("Output: "
						+ isStringOnlyAlphabet(str3));

		// Checking for empty String
		System.out.println("\nTest Case 4:");
		String str4 = "";
		System.out.println("Input: " + str4);

		// Calling over above string ""
		System.out.println("Output: "
						+ isStringOnlyAlphabet(str4));
	}
}
