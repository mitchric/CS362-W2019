// Richard Mitchell - mitchric
// Tucker Lavell - lavellt
// Matthew McLean - mcleanm


import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!


// added new branch


public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   
   public void testManualTest()
   {
//You can use this function to implement your manual testing	   
	   
   }
   
   
   public void testYourFirstPartition()
   {
	 //You can use this function to implement your First Partition testing	   

   }
   
   public void testYourSecondPartition(){
		 //You can use this function to implement your Second Partition testing	   

   }
   //You need to create more test cases for your Partitions if you need to 
   
   public void testIsValid()
   {
	   //You can use this function for programming based testing

   }

   public void testIsValidUnitTest() {
	  UrlValidator urlVal = new UrlValidator();

	  System.out.println("Unit testing url http://www.apache.org"); 
	  System.out.println("Expecting true");
	  System.out.println("Result = " + urlVal.isValid("http://www.apache.org"));

	  System.out.println("\nUnit testing url ftp://billgates:moremoney@files.microsoft.com/special"); 
	  System.out.println("Expecting true");
	  System.out.println("Result = " + urlVal.isValid("ftp://billgates:moremoney@files.microsoft.com/special"));
	  
	  
	  System.out.println("\nUnit testing url 3ht://yahoo.com"); 
	  System.out.println("Expecting false");
	  System.out.println("Result = " + urlVal.isValid("3ht://yahoo.com"));
	  
	  System.out.println("\nUnit testing url http:/bing.com"); 
	  System.out.println("Expecting false");
	  System.out.println("Result = " + urlVal.isValid("http:/bing.com"));
	  
	  
	  System.out.println("\nUnit testing url http:marvel.com"); 
	  System.out.println("Expecting false");
	  System.out.println("Result = " + urlVal.isValid("http:marvel.com"));
	  
	  System.out.println("\nUnit testing url http/starwars.com"); 
	  System.out.println("Expecting false");
	  System.out.println("Result = " + urlVal.isValid("http/starwars.com")); 
	  
	  System.out.println("\nUnit testing url ://nfl.com"); 
	  System.out.println("Expecting false");
	  System.out.println("Result = " + urlVal.isValid("://nfl.com"));
   }
   
   public void testIsValidSchemeUnitTest() {
	  UrlValidator urlVal = new UrlValidator();

	  System.out.println("\nUnit testing scheme http://"); 
	  System.out.println("Expecting true");
	  System.out.println("Result = " + urlVal.isValidScheme("http://"));

	  System.out.println("\nUnit testing scheme ftp://"); 
	  System.out.println("Expecting true");
	  System.out.println("Result = " + urlVal.isValidScheme("ftp://"));
	  
	  
	  System.out.println("\nUnit testing scheme 3ht://"); 
	  System.out.println("Expecting false");
	  System.out.println("Result = " + urlVal.isValidScheme("3ht://"));
	  
	  System.out.println("\nUnit testing scheme http:/"); 
	  System.out.println("Expecting false");
	  System.out.println("Result = " + urlVal.isValidScheme("http:/"));
	  
	  
	  System.out.println("\nUnit testing scheme http:"); 
	  System.out.println("Expecting false");
	  System.out.println("Result = " + urlVal.isValidScheme("http:"));
	  
	  System.out.println("\nUnit testing scheme http/"); 
	  System.out.println("Expecting false");
	  System.out.println("Result = " + urlVal.isValidScheme("http/")); 
	  
	  System.out.println("\nUnit testing scheme ://"); 
	  System.out.println("Expecting false");
	  System.out.println("Result = " + urlVal.isValidScheme("://"));
   } 
   
   public void testIsValidQueryUnitTest() {
	  UrlValidator urlVal = new UrlValidator();
	  
	  System.out.println("\nUnit testing query ?hpt=sitenav");
	  System.out.println("Expecting true");
	  System.out.println("Result = " + urlVal.isValidQuery("?hpt=sitenav"));
	  
	  System.out.println("\nUnit testing query ?action=view");
	  System.out.println("Expecting true");
	  System.out.println("Result = " + urlVal.isValidQuery("?action=view"));
	  
	  System.out.println("\nUnit testing query ?action=edit&mode=up");
	  System.out.println("Expecting true");
	  System.out.println("Result = " + urlVal.isValidQuery("?action=edit&mode=up"));
	  
	  System.out.println("\nUnit testing empty query");
	  System.out.println("Expecting true");
	  System.out.println("Result = " + urlVal.isValidQuery(""));
   }
}
