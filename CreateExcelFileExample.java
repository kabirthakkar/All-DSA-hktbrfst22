import java.io.*;
import org.apache.poi.hssf.usermodel.HSSFSheet;
import org.apache.poi.hssf.usermodel.HSSFWorkbook;
import org.apache.poi.hssf.usermodel.HSSFCell;
import org.apache.poi.hssf.usermodel.HSSFRow;

public class CreateExcelFileExample {
	// declare file name to be create
	static String filename = "C:\\temp\\selfie\\Balance.xls";
	public FileInputStream fis = null;
	public static HSSFWorkbook workbook = null;
	public static HSSFSheet sheet = null;
	public static HSSFRow row = null;
	public HSSFCell cell = null;

	public static void main(String[] args) {
		CreateExcelFileExample example = new CreateExcelFileExample();
		int row= example.rowCount();
		example.excelSheetMake(row);
		example.rowCount();
	}
	
	public void excelSheetMake(int rownu) {
		int r=rownu;
		try {
			// creating an instance of HSSFWorkbook class
			workbook = new HSSFWorkbook();
			// invoking creatSheet() method and passing the name of the sheet to be created
			sheet = workbook.createSheet("January");
			// creating the 0th row using the createRow() method
			HSSFRow rowhead = sheet.createRow((short) 0);
			// creating cell by using the createCell() method and setting the values to the
			// cell by using the setCellValue() method
			rowhead.createCell(0).setCellValue("S.No.");
			rowhead.createCell(1).setCellValue("Customer Name");
			rowhead.createCell(2).setCellValue("Account Number");
			rowhead.createCell(3).setCellValue("e-mail");
			rowhead.createCell(4).setCellValue("Balance");
			// creating the 1st row
				row = sheet.createRow((short) r);
				// inserting data in the first row
				row.createCell(0).setCellValue("1");
				row.createCell(1).setCellValue("John William");
				row.createCell(2).setCellValue("9999999");
				row.createCell(3).setCellValue("william.john@gmail.com");
				row.createCell(4).setCellValue("700000.00");
				FileOutputStream fileOut = new FileOutputStream(filename);
				workbook.write(fileOut);
				// closing the Stream
				fileOut.close();
				// closing the workbook
				workbook.close();
			// prints the message on the console
			System.out.println("Excel file has been generated successfully.");
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public int rowCount() {
		try {
			fis = new FileInputStream(filename);
			workbook = new HSSFWorkbook(fis);
			sheet = workbook.getSheet("January");
			int rowNum = sheet.getLastRowNum();
			System.out.println("Total Number of Rows in the excel is : " + rowNum);
			return rowNum;
		} catch (Throwable e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			return 0;
		}

	}
}
