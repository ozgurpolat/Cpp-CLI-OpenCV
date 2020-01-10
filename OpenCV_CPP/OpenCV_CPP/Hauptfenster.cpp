#include "Hauptfenster.h"

using namespace System::IO;
using namespace cv;
using namespace std;

Mat cvImg;

System::Void OpenCVCPP::Hauptfenster::Button_LoadImage_Click(System::Object^ sender, System::EventArgs^ e)
{
	// Open a dialog window and store the result 
	System::Windows::Forms::DialogResult result = openFileDialog1->ShowDialog();

	// Check that dialog window was succesfully opened
	if (result == System::Windows::Forms::DialogResult::OK) {

		// Get the image filename
		imgFileName = openFileDialog1->FileName;

		// Marshal.StringToHGlobalAnsi(String) Method Copies the contents of a managed String into unmanaged memory,
		// converting into ANSI format as it copies. StringToHGlobalAnsi copies the contents of a managed String 
		// object into native heap, and then converts it into American National Standards Institute (ANSI) format 
		// on the fly. This method allocates the required native heap memory. The following function takes a managed
		// string type and returns a char pointer which can be used like a string (old C type string) in opencv imread() method
		char* convertedFileName = convertManagedStringToANSIFormat(imgFileName);

		// Try to open the data
		try {

			// https://codeyarns.com/2015/08/27/depth-and-type-of-matrix-in-opencv/

			cvImg = imread(convertedFileName, cv::IMREAD_UNCHANGED);

			// Resizing the image so that cvImgResized.cols is divisible by 4
			Mat cvImgResized = resizeMatImageObject(cvImg, 4);

			Bitmap^ bmpImg;

			// cvImg.channels() returns the number of channels each picture has
			if (cvImg.channels() == 1) {
				// The following two line of code had problem with 16 bpp graysacel 4 channel image
				// The 16 bpp gray scale image was created using GIMP. We probably need to determine
				// the depth() and the type() of Mat object and use a different format -> ( cv::COLOR_GRAY2RGB)
				// cvtColor(cvImgResized, color, cv::COLOR_GRAY2RGB, 3); //  Converting it to color
				// bmpImg = gcnew Bitmap(color.cols, color.rows, color.step1(), Imaging::PixelFormat::Format24bppRgb, (IntPtr)color.data);

				// If the image is has one channel, then read it as grayscale
				Mat grayscale = imread(convertedFileName, cv::IMREAD_GRAYSCALE);

				Mat color;

				cvtColor(grayscale, color, cv::COLOR_GRAY2RGB, 3);

				bmpImg = gcnew Bitmap(color.cols, color.rows, color.step1(), Imaging::PixelFormat::Format24bppRgb, (IntPtr)color.data);

				// The Bitmap is by default (objects are passed by reference) passed to a picture box by a reference.
				// The 'frame' variable goes out of scope when the function returns. Thus, the pointer is dead, and 
				// you have a GDI object with a pointer to garbage data.
				bmpMain = gcnew Bitmap(bmpImg);
			}
			else if (cvImg.channels() == 3) {
				// There are many example code online with (3 * cvImg.rows) or (6 * cvImg.rows) for some png images
				// But often the values these calculations return seems to be wrong and it is better to use
				// the mat_obj.step1() which returns normalised value and it is guaranteed to work.
				bmpImg = gcnew Bitmap(cvImgResized.cols, cvImgResized.rows, cvImgResized.step1(), Imaging::PixelFormat::Format24bppRgb, (IntPtr)cvImgResized.data);

				// See above
				bmpMain = gcnew Bitmap(bmpImg);

			}
			else if (cvImg.channels() == 4) {

				// Using cvImg.step1() is better here
				bmpImg = gcnew Bitmap(cvImgResized.cols, cvImgResized.rows, cvImgResized.step1(), Imaging::PixelFormat::Format32bppRgb, (IntPtr)cvImgResized.data);

				// See above
				bmpMain = gcnew Bitmap(bmpImg);
			}

			panel_MainImage->BackgroundImage = bmpMain;

			// Buttons are intitaly disabled and enabled only after an image is loaded
			enableDisableButtons("enable");

			textBox_MainImage->Text = "Image width: " + cvImg.rows + Environment::NewLine +
										"Image height: " + cvImg.cols + Environment::NewLine +
										"Image type: " + cvImg.type() + Environment::NewLine +
										"Image depth: " + cvImg.depth() + Environment::NewLine +
										"Number of channels: " + cvImg.channels();
		}
		catch (cv::Exception ex) {
			// Show the OpenCV exception in a message box
			std::string test = ex.msg;

			System::String^ verwString = marshal_as<System::String^>(test);

			MessageBox::Show("OpenCV exception: " + verwString);
		}
		catch (System::Exception ^ exception) {

			// Show the Window exception in a message box
			MessageBox::Show("Windows exception: " + exception->Message);
		}
	}
}

System::Void OpenCVCPP::Hauptfenster::Button_LoadLightPatternImage_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	// Open a dialog window and store the result 
	System::Windows::Forms::DialogResult result = openFileDialog1->ShowDialog();

	// Check that dialog window was succesfully opened
	if (result == System::Windows::Forms::DialogResult::OK) {

		// Get the image filename
		imgLightPatternFileName = openFileDialog1->FileName;

		// Marshal.StringToHGlobalAnsi(String) Method Copies the contents of a managed String into unmanaged memory,
		// converting into ANSI format as it copies. StringToHGlobalAnsi copies the contents of a managed String 
		// object into native heap, and then converts it into American National Standards Institute (ANSI) format 
		// on the fly. This method allocates the required native heap memory. The following function takes a managed
		// string type and returns a char pointer which can be used like a string (old C type string) in opencv imread() method
		char* convertedFileName = convertManagedStringToANSIFormat(imgLightPatternFileName);

		// Try to open the data
		try {

			cvImg = imread(convertedFileName, cv::IMREAD_UNCHANGED);

			// Resizing the image so that cvImgResized.cols is divisible by 4
			Mat cvImgResized = resizeMatImageObject(cvImg, 4);

			Bitmap^ bmpImg;

			// cvImg.channels() returns the number of channels each picture has
			if (cvImg.channels() == 1) {
				// The following two line of code had problem with 16 bpp graysacel 4 channel image
				// The 16 bpp gray scale image was created using GIMP. We probably need to determine
				// the depth() and the type() of Mat object and use a different format -> ( cv::COLOR_GRAY2RGB)
				//cvtColor(cvImgResized, color, cv::COLOR_GRAY2RGB, 3); //  Converting it to color
				//bmpImg = gcnew Bitmap(color.cols, color.rows, color.step1(), Imaging::PixelFormat::Format24bppRgb, (IntPtr)color.data);

				// If the image is has one channel, then read it as grayscale
				Mat grayscale = imread(convertedFileName, cv::IMREAD_GRAYSCALE);

				Mat color;

				cvtColor(grayscale, color, cv::COLOR_GRAY2RGB, 3);

				bmpImg = gcnew Bitmap(color.cols, color.rows, color.step1(), Imaging::PixelFormat::Format24bppRgb, (IntPtr)color.data);

				// The Bitmap is by default (objects are passed by reference) passed to a picture box by a reference.
				// The 'frame' variable goes out of scope when the function returns. Thus, the pointer is dead, and 
				// you have a GDI object with a pointer to garbage data.
				bmpLightPattern = gcnew Bitmap(bmpImg);

			}
			else if (cvImg.channels() == 3) {
				// There are many example code online with (3 * cvImg.rows) or (6 * cvImg.rows) for some png images
				// But often the values these calculations return seems to be wrong and it is better to use
				// the mat_obj.step1() which returns normalised value and it is guaranteed to work.
				bmpImg = gcnew Bitmap(cvImgResized.cols, cvImgResized.rows, cvImgResized.step1(), Imaging::PixelFormat::Format24bppRgb, (IntPtr)cvImgResized.data);

				// See above
				bmpLightPattern = gcnew Bitmap(bmpImg);
			}
			else if (cvImg.channels() == 4) {

				// Using cvImg.step1() is better here
				bmpImg = gcnew Bitmap(cvImgResized.cols, cvImgResized.rows, cvImgResized.step1(), Imaging::PixelFormat::Format32bppRgb, (IntPtr)cvImgResized.data);

				// See above
				bmpLightPattern = gcnew Bitmap(bmpImg);
			}

			panel_LoadLightPattern->BackgroundImage = bmpLightPattern;
		}
		// catch Opencv related exceptions
		catch (cv::Exception ex) {
			// Show the OpenCV exception in a message box
			std::string test = ex.msg;

			System::String^ verwString = marshal_as<System::String^>(test);

			MessageBox::Show("OpenCV exception: " + verwString);
		}
		// catch System related exceptions
		catch (System::Exception ^ exception) {

			// Show the Window exception in a message box
			MessageBox::Show("Windows exception: " + exception->Message);
		}
	}
}

System::Void OpenCVCPP::Hauptfenster::Button_SplitChannels_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	// Marshal.StringToHGlobalAnsi(String) Method Copies the contents of a managed String into unmanaged memory,
	// converting into ANSI format as it copies. StringToHGlobalAnsi copies the contents of a managed String 
	// object into native heap, and then converts it into American National Standards Institute (ANSI) format 
	// on the fly. This method allocates the required native heap memory. The following function takes a managed
	// string type and returns a char pointer which can be used like a string (old C type string) in opencv imread() method
	char* convertedFileName = convertManagedStringToANSIFormat(imgFileName);

	// Try to open the data if fails catch exceptions
	try {

		cvImg = imread(convertedFileName, cv::IMREAD_UNCHANGED);

		// Resizing the image so that cvImgResized.cols is divisible by 4
		Mat cvImgResized = resizeMatImageObject(cvImg, 4);

		Bitmap^ bmpImg;
		Bitmap^ bmpB;
		Bitmap^ bmpG;
		Bitmap^ bmpR;
		Bitmap^ bmpA;

		Imaging::PixelFormat imgFormat;

		// cvImg.channels() returns the number of channels each picture has
		// if the image is already grayscale, there is not need to perform
		// split on the image, just read the image and display it in the 
		// first (Blue Channel Window)
		if (cvImg.channels() == 1) {

			Mat imgGrayscale = imread(convertedFileName, cv::IMREAD_GRAYSCALE);

			Mat imgColor;

			cvtColor(imgGrayscale, imgColor, cv::COLOR_GRAY2RGB, 3);

			imgFormat = Imaging::PixelFormat::Format24bppRgb;

			bmpImg = gcnew Bitmap(imgColor.cols, imgColor.rows, imgColor.step1(), imgFormat, (IntPtr)imgColor.data);

			// The Bitmap is by default (objects are passed by reference) passed to a picture box by a reference.
			// The 'frame' variable goes out of scope when the function returns. Thus, the pointer is dead, 
			// and you have a GDI object with a pointer to garbage data.
			bmpBlueChannel = gcnew Bitmap(bmpImg);
			bmpGreenChannel = nullptr;
			bmpRedChannel = nullptr;
		}
		else if (cvImg.channels() == 3) {

			Mat splitChannels[3];

			split(cvImgResized, splitChannels);

			Mat B;
			Mat G;
			Mat R;

			// Split channels now are all grayscale,
			// We need to convert them to color to display them
			cvtColor(splitChannels[0], B, cv::COLOR_GRAY2RGB, 3);
			cvtColor(splitChannels[1], G, cv::COLOR_GRAY2RGB, 3);
			cvtColor(splitChannels[2], R, cv::COLOR_GRAY2RGB, 3);

			imgFormat = Imaging::PixelFormat::Format24bppRgb;

			bmpB = gcnew Bitmap(B.cols, B.rows, B.step1(), imgFormat, (IntPtr)B.data);
			bmpG = gcnew Bitmap(G.cols, G.rows, G.step1(), imgFormat, (IntPtr)G.data);
			bmpR = gcnew Bitmap(R.cols, R.rows, R.step1(), imgFormat, (IntPtr)R.data);

			// The Bitmap is by default (objects are passed by reference) passed to a picture box by a reference.
			// The 'frame' variable goes out of scope when the function returns. Thus, the pointer is dead, 
			// and you have a GDI object with a pointer to garbage data.
			bmpBlueChannel = gcnew Bitmap(bmpB);
			bmpGreenChannel = gcnew Bitmap(bmpG);
			bmpRedChannel = gcnew Bitmap(bmpR);
		}
		else if (cvImg.channels() == 4) {

			Mat splitChannels[4];

			split(cvImgResized, splitChannels);

			Mat B;
			Mat G;
			Mat R;
			Mat A;

			// Split channels now are all grayscale,
			// We need to convert them to color to display them
			cvtColor(splitChannels[0], B, cv::COLOR_GRAY2RGB, 3);
			cvtColor(splitChannels[1], G, cv::COLOR_GRAY2RGB, 3);
			cvtColor(splitChannels[2], R, cv::COLOR_GRAY2RGB, 3);
			cvtColor(splitChannels[3], A, cv::COLOR_GRAY2RGB, 3);

			imgFormat = Imaging::PixelFormat::Format24bppRgb;

			bmpB = gcnew Bitmap(B.cols, B.rows, B.step1(), imgFormat, (IntPtr)B.data);
			bmpG = gcnew Bitmap(G.cols, G.rows, G.step1(), imgFormat, (IntPtr)G.data);
			bmpR = gcnew Bitmap(R.cols, R.rows, R.step1(), imgFormat, (IntPtr)R.data);
			// No need to show the alpha channel
			//bmpA = gcnew Bitmap(A.cols, A.rows, A.step1(), imgFormat, (IntPtr)A.data);

			// The Bitmap is by default (objects are passed by reference) passed to a picture box by a reference.
			// The 'frame' variable goes out of scope when the function returns. Thus, the pointer is dead, 
			// and you have a GDI object with a pointer to garbage data.
			bmpBlueChannel = gcnew Bitmap(bmpB);
			bmpGreenChannel = gcnew Bitmap(bmpG);
			bmpRedChannel = gcnew Bitmap(bmpR);
		}

		panel_BlueChannel->BackgroundImage = bmpBlueChannel;
		panel_GreenChannel->BackgroundImage = bmpGreenChannel;
		panel_RedChannel->BackgroundImage = bmpRedChannel;

		if (cvImg.channels() >= 3) {
			textBox_BlueChannel->Text = "Blue channel with its individual intensity. ";
			textBox_BlueChannel->Text = "Splitting an image is taking an image with multiple channels such as red green blue " +
				"and splitting them to their individual Mat objects. After the split, the images become " +
				"grayscale because there is only one channel. But here we are looking at the intensity of " +
				"blue channel image. ";
			textBox_GreenChannel->Text = "Green channel with its individual intensity. ";
			textBox_RedChannel->Text = "Red channel with its individual intensity. ";

		}
		else {
			textBox_BlueChannel->Text = "Loaded image is grayscale and there is only a single channel. ";
		}
	}
	// catch Opencv related exceptions
	catch (cv::Exception ex) {
		// Show the OpenCV exception in a message box
		std::string test = ex.msg;

		System::String^ verwString = marshal_as<System::String^>(test);

		MessageBox::Show("OpenCV exception: " + verwString);
	}
	// catch System related exceptions
	catch (System::Exception ^ exception) {

		// Show the Window exception in a message box
		MessageBox::Show("Windows exception: " + exception->Message);
	}
}

System::Void OpenCVCPP::Hauptfenster::Button_RemoveBGR_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	// Marshal.StringToHGlobalAnsi(String) Method Copies the contents of a managed String into unmanaged memory,
	// converting into ANSI format as it copies. StringToHGlobalAnsi copies the contents of a managed String 
	// object into native heap, and then converts it into American National Standards Institute (ANSI) format 
	// on the fly. This method allocates the required native heap memory. The following function takes a managed
	// string type and returns a char pointer which can be used like a string (old C type string) in opencv imread() method
	char* convertedFileName = convertManagedStringToANSIFormat(imgFileName);

	// Try to open the data if fails catch exceptions
	try {

		cvImg = imread(convertedFileName, cv::IMREAD_UNCHANGED);

		// Resizing the image so that cvImgResized.cols is divisible by 4
		Mat cvImgResized = resizeMatImageObject(cvImg, 4);

		Bitmap^ bmpImg;
		Bitmap^ bmpB;
		Bitmap^ bmpG;
		Bitmap^ bmpR;
		Bitmap^ bmpA;

		Imaging::PixelFormat imgFormat;

		// cvImg.channels() returns the number of channels each picture has
		// if the image is already grayscale, there is not need to perform
		// split on the image, just read the image and display it in the 
		// first (Blue Channel Window)
		if (cvImg.channels() == 1) {

			Mat imgGrayscale = imread(convertedFileName, cv::IMREAD_GRAYSCALE);

			Mat imgColor;

			cvtColor(imgGrayscale, imgColor, cv::COLOR_GRAY2RGB, 3);

			imgFormat = Imaging::PixelFormat::Format24bppRgb;

			bmpImg = gcnew Bitmap(imgColor.cols, imgColor.rows, imgColor.step1(), imgFormat, (IntPtr)imgColor.data);

			// The Bitmap is by default (objects are passed by reference) passed to a picture box by a reference.
			// The 'frame' variable goes out of scope when the function returns. Thus, the pointer is dead, 
			// and you have a GDI object with a pointer to garbage data.
			bmpBlueChannel = gcnew Bitmap(bmpImg);
			bmpGreenChannel = nullptr;
			bmpRedChannel = nullptr;

		}
		else if (cvImg.channels() == 3) {

			//Mat splitChannels[3];

			//split(cvImgResized, splitChannels);

			Mat B = cvImgResized.clone();
			Mat G = cvImgResized.clone();
			Mat R = cvImgResized.clone();

			// Removing each channel by iterating over pixel values and
			// multiplying the array for the channel to be removed with zero
			B = removeChannel(B, 0, 3);
			G = removeChannel(G, 1, 3);
			R = removeChannel(R, 2, 3);

			imgFormat = Imaging::PixelFormat::Format24bppRgb;

			bmpB = gcnew Bitmap(B.cols, B.rows, B.step1(), imgFormat, (IntPtr)B.data);
			bmpG = gcnew Bitmap(G.cols, G.rows, G.step1(), imgFormat, (IntPtr)G.data);
			bmpR = gcnew Bitmap(R.cols, R.rows, R.step1(), imgFormat, (IntPtr)R.data);

			// The Bitmap is by default (objects are passed by reference) passed to a picture box by a reference.
			// The 'frame' variable goes out of scope when the function returns. Thus, the pointer is dead, 
			// and you have a GDI object with a pointer to garbage data.
			bmpBlueChannel = gcnew Bitmap(bmpB);
			bmpGreenChannel = gcnew Bitmap(bmpG);
			bmpRedChannel = gcnew Bitmap(bmpR);
		}
		else if (cvImg.channels() == 4) {

			Mat B = cvImgResized.clone();
			Mat G = cvImgResized.clone();
			Mat R = cvImgResized.clone();

			// Removing each channel by iterating over pixel values and
			// multiplying the array for the channel to be removed with zero
			// Also specifying the number of channels so that the method can use correct variable
			B = removeChannel(B, 0, 4);
			G = removeChannel(G, 1, 4);
			R = removeChannel(R, 2, 4);

			imgFormat = Imaging::PixelFormat::Format32bppRgb;

			bmpB = gcnew Bitmap(B.cols, B.rows, B.step1(), imgFormat, (IntPtr)B.data);
			bmpG = gcnew Bitmap(G.cols, G.rows, G.step1(), imgFormat, (IntPtr)G.data);
			bmpR = gcnew Bitmap(R.cols, R.rows, R.step1(), imgFormat, (IntPtr)R.data);
			// No need to show the alpha channel
			//bmpA = gcnew Bitmap(A.cols, A.rows, A.step1(), imgFormat, (IntPtr)A.data);

			// The Bitmap is by default (objects are passed by reference) passed to a picture box by a reference.
			// The 'frame' variable goes out of scope when the function returns. Thus, the pointer is dead, 
			// and you have a GDI object with a pointer to garbage data.
			bmpBlueChannel = gcnew Bitmap(bmpB);
			bmpGreenChannel = gcnew Bitmap(bmpG);
			bmpRedChannel = gcnew Bitmap(bmpR);
		}

		panel_BlueChannel->BackgroundImage = bmpBlueChannel;
		panel_GreenChannel->BackgroundImage = bmpGreenChannel;
		panel_RedChannel->BackgroundImage = bmpRedChannel;

		if (cvImg.channels() >= 3) {
			textBox_BlueChannel->Text = "Image without the blue channel.";
			textBox_BlueChannel->Text = "Here we set the pixel values in blue channel to zero. By doing this " +
										"we remove the blue channel. See the following code: " +
										"img.at<Vec3b>(r, c)[0] = img.at<Vec3b>(r, c)[0] * 0; ";
			textBox_GreenChannel->Text = "Image without the green channel.";
			textBox_RedChannel->Text = "Image without the red channel.";
		}
		else {
			textBox_BlueChannel->Text = "Loaded image is grayscale and there is only a single channel. ";
		}

	}
	// catch Opencv related exceptions
	catch (cv::Exception ex) {
		// Show the OpenCV exception in a message box
		std::string test = ex.msg;

		System::String^ verwString = marshal_as<System::String^>(test);

		MessageBox::Show("OpenCV exception: " + verwString);
	}
	// catch System related exceptions
	catch (System::Exception ^ exception) {

		// Show the Window exception in a message box
		MessageBox::Show("Windows exception: " + exception->Message);
	}
}

System::Void OpenCVCPP::Hauptfenster::Button_GrayFilter_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	// Marshal.StringToHGlobalAnsi(String) Method Copies the contents of a managed String into unmanaged memory,
	// converting into ANSI format as it copies. StringToHGlobalAnsi copies the contents of a managed String 
	// object into native heap, and then converts it into American National Standards Institute (ANSI) format 
	// on the fly. This method allocates the required native heap memory. The following function takes a managed
	// string type and returns a char pointer which can be used like a string (old C type string) in opencv imread() method
	char* convertedFileName = convertManagedStringToANSIFormat(imgFileName);

	// Versuche die Datei zu öffnen
	try {

		cvImg = imread(convertedFileName, cv::IMREAD_UNCHANGED);

		// Resizing the image so that cvImgResized.cols is divisible by 4
		Mat cvImgResized = resizeMatImageObject(cvImg, 4);

		Mat gray0;
		Mat gray;
		Mat color;

		Bitmap^ bmpImg;

		Imaging::PixelFormat immFormat;

		// cvImg.channels() returns the number of channels each picture has
		// if the image is already grayscale, there is not need to perform
		// grayscale filtering/conversion
		if (cvImg.channels() == 1) {

			Mat grayscale = imread(convertedFileName, cv::IMREAD_GRAYSCALE);

			Mat color;

			cvtColor(grayscale, color, cv::COLOR_GRAY2RGB, 3);

			immFormat = Imaging::PixelFormat::Format24bppRgb;

			bmpImg = gcnew Bitmap(color.cols, color.rows, color.step1(), immFormat, (IntPtr)color.data);

			// The Bitmap is by default (objects are passed by reference) passed to a picture box by a reference.
			// The 'frame' variable goes out of scope when the function returns. Thus, the pointer is dead, and 
			// you have a GDI object with a pointer to garbage data.
			bmpGrayscale = gcnew Bitmap(bmpImg);
		}
		else {

			cvtColor(cvImgResized, gray0, cv::COLOR_BGR2GRAY);
			cvtColor(gray0, color, cv::COLOR_GRAY2RGB, 3); //  Converting it back to color

			immFormat = Imaging::PixelFormat::Format24bppRgb;

			bmpImg = gcnew Bitmap(color.cols, color.rows, color.step1(), immFormat, (IntPtr)color.data);

			// The Bitmap is by default (objects are passed by reference) passed to a picture box by a reference.
			// The 'frame' variable goes out of scope when the function returns. Thus, the pointer is dead, and 
			// you have a GDI object with a pointer to garbage data.
			bmpGrayscale = gcnew Bitmap(bmpImg);
		}

		panel_Grayscale->BackgroundImage = bmpGrayscale;

		textBox_Grayscale->Text =	"Here we use cvtColor method to convert an image with three or four channels. " +
									"We use the following: cvtColor(cvImgResized, gray0, cv::COLOR_BGR2GRAY); " +
									"In order to display the image in our window we need to convert it color image with "
									"there channels. Each channel will be holding the same pixel values. This is done "
									"in order to convert the OpenCv Mat object to a bitmap and display it in our panel " +
									"as a background image.";
	}
	// catch Opencv related exceptions
	catch (cv::Exception ex) {
		// Show the OpenCV exception in a message box
		std::string test = ex.msg;

		System::String^ verwString = marshal_as<System::String^>(test);

		MessageBox::Show("OpenCV exception: " + verwString);
	}
	// catch System related exceptions
	catch (System::Exception ^ exception) {

		// Show the Window exception in a message box
		MessageBox::Show("Windows exception: " + exception->Message);
	}
}

System::Void OpenCVCPP::Hauptfenster::trackBar_BlurIndex_Scroll(System::Object ^ sender, System::EventArgs ^ e)
{
	label_Blur->Text = trackBar_BlurIndex->Value.ToString();
}

System::Void OpenCVCPP::Hauptfenster::Button_BlurFilter_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	// Marshal.StringToHGlobalAnsi(String) Method Copies the contents of a managed String into unmanaged memory,
	// converting into ANSI format as it copies. StringToHGlobalAnsi copies the contents of a managed String 
	// object into native heap, and then converts it into American National Standards Institute (ANSI) format 
	// on the fly. This method allocates the required native heap memory. The following function takes a managed
	// string type and returns a char pointer which can be used like a string (old C type string) in opencv imread() method
	char* convertedFileName = convertManagedStringToANSIFormat(imgFileName);

	// Try to open the data if fails catch exceptions
	try {

		cvImg = imread(convertedFileName, cv::IMREAD_UNCHANGED);

		// Resizing the image so that cvImgResized.cols is divisible by 4
		Mat cvImgResized = resizeMatImageObject(cvImg, 4);

		Bitmap^ bmpImg;
		Imaging::PixelFormat imgFormat;

		// cvImg.channels() returns the number of channels each picture has
		// if the image is already grayscale, there is not need to perform
		// grayscale filtering/conversion
		if (cvImg.channels() == 1) {

			Mat imgGrayscale = imread(convertedFileName, cv::IMREAD_GRAYSCALE);

			Mat imgBlur;

			blur(imgGrayscale, imgBlur, cv::Size(trackBar_BlurIndex->Value, trackBar_BlurIndex->Value));

			Mat imgColor;

			cvtColor(imgBlur, imgColor, cv::COLOR_GRAY2RGB, 3);

			imgFormat = Imaging::PixelFormat::Format24bppRgb;

			bmpImg = gcnew Bitmap(imgColor.cols, imgColor.rows, imgColor.step1(), imgFormat, (IntPtr)imgColor.data);

			// The Bitmap is by default (objects are passed by reference) passed to a picture box by a reference.
			// The 'frame' variable goes out of scope when the function returns. Thus, the pointer is dead, and 
			// you have a GDI object with a pointer to garbage data.
			bmpBlur = gcnew Bitmap(bmpImg);
		}
		else if (cvImg.channels() == 3) {

			Mat imgBlur;

			blur(cvImgResized, imgBlur, cv::Size(trackBar_BlurIndex->Value, trackBar_BlurIndex->Value));

			imgFormat = Imaging::PixelFormat::Format24bppRgb;

			bmpImg = gcnew Bitmap(imgBlur.cols, imgBlur.rows, imgBlur.step1(), imgFormat, (IntPtr)imgBlur.data);

			// The Bitmap is by default (objects are passed by reference) passed to a picture box by a reference.
			// The 'frame' variable goes out of scope when the function returns. Thus, the pointer is dead, and 
			// you have a GDI object with a pointer to garbage data.
			bmpBlur = gcnew Bitmap(bmpImg);
		}
		else if (cvImg.channels() == 4) {

			Mat imgBlur;

			blur(cvImgResized, imgBlur, cv::Size(trackBar_BlurIndex->Value, trackBar_BlurIndex->Value));

			imgFormat = Imaging::PixelFormat::Format32bppRgb;

			bmpImg = gcnew Bitmap(imgBlur.cols, imgBlur.rows, imgBlur.step1(), imgFormat, (IntPtr)imgBlur.data);

			// The Bitmap is by default (objects are passed by reference) passed to a picture box by a reference.
			// The 'frame' variable goes out of scope when the function returns. Thus, the pointer is dead, and 
			// you have a GDI object with a pointer to garbage data.
			bmpBlur = gcnew Bitmap(bmpImg);
		}

		panel_Blur->BackgroundImage = bmpBlur;

		textBox_Blur-> Text =	"Smoothing, also called blurring, is a simple and frequently used image processing operation. " +
								"There are many reasons for smoothing. One of the common reasons is noise reduction. To perform a smoothing" +
								"operation we will apply a filter to our image. The most common type of filters are linear, in which an " +
								"output pixel’s value is determined as a weighted sum of input pixel values. It helps to visualize a filter " + 
								"as a window of coefficients sliding across the image.";
	}
	// catch Opencv related exceptions
	catch (cv::Exception ex) {
		// Show the OpenCV exception in a message box
		std::string test = ex.msg;

		System::String^ verwString = marshal_as<System::String^>(test);

		MessageBox::Show("OpenCV exception: " + verwString);
	}
	// catch System related exceptions
	catch (System::Exception ^ exception) {

		// Show the Window exception in a message box
		MessageBox::Show("Windows exception: " + exception->Message);
	}
}

System::Void OpenCVCPP::Hauptfenster::Button_Sobel_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	// Marshal.StringToHGlobalAnsi(String) Method Copies the contents of a managed String into unmanaged memory,
	// converting into ANSI format as it copies. StringToHGlobalAnsi copies the contents of a managed String 
	// object into native heap, and then converts it into American National Standards Institute (ANSI) format 
	// on the fly. This method allocates the required native heap memory. The following function takes a managed
	// string type and returns a char pointer which can be used like a string (old C type string) in opencv imread() method
	char* convertedFileName = convertManagedStringToANSIFormat(imgFileName);

	// Try to open the data if fails catch exceptions
	try {

		/*	One of the most important convolutions is the computation of derivatives in an image (or an approximation to them).
			Let’s imagine we want to detect the edges present in the image. If we consider any image we can see how intensity
			changes in an edge. We can easily notice that in an edge, the pixel intensity changes in a notorious way.
			A good way to express changes is by using derivatives. A high change in gradient indicates a major change in the image.
			A method to detect edges in an image can be performed by locating pixel locations where the gradient is higher than
			its neighbors (or to generalize, higher than a threshold).
		*/

		// Read an image and crate a Mat object
		cvImg = imread(convertedFileName, cv::IMREAD_UNCHANGED);

		// Resizing the image so that cvImgResized.cols is divisible by 4
		Mat cvImgResized = resizeMatImageObject(cvImg, 4);

		Mat cvImgGray;
		Mat grad;

		int scale = 1;
		int delta = 0;
		int ddepth = CV_16S;

		int c;

		// First, we apply a GaussianBlur to our image to reduce the noise ( kernel size = 3 )
		GaussianBlur(cvImgResized, cvImgResized, cv::Size(3, 3), 0, 0, BORDER_DEFAULT);

		// Now we convert our filtered image to grayscale:
		cvtColor(cvImgResized, cvImgGray, COLOR_BGR2GRAY);

		// Second, we calculate the “derivatives” in x and y directions. For this, we use the function Sobel as shown below:
		// Generate grad_x and grad_y
		Mat grad_x, grad_y;
		Mat abs_grad_x, abs_grad_y;

		/// Gradient X
		//Scharr( src_gray, grad_x, ddepth, 1, 0, scale, delta, BORDER_DEFAULT );

		/*The function takes the following arguments:
			src_gray: In our example, the input image.Here it is CV_8U
			grad_x / grad_y : The output image.
			ddepth : The depth of the output image.We set it to CV_16S to avoid overflow.
			x_order : The order of the derivative in x direction.
			y_order : The order of the derivative in y direction.
			scale, deltaand BORDER_DEFAULT : We use default values.
		*/

		Sobel(cvImgGray, grad_x, ddepth, 1, 0, 3, scale, delta, BORDER_DEFAULT);

		// We convert our partial results back to CV_8U:
		convertScaleAbs(grad_x, abs_grad_x);

		/// Gradient Y
		//Scharr( src_gray, grad_y, ddepth, 0, 1, scale, delta, BORDER_DEFAULT );
		Sobel(cvImgGray, grad_y, ddepth, 0, 1, 3, scale, delta, BORDER_DEFAULT);

		// We convert our partial results back to CV_8U:
		convertScaleAbs(grad_y, abs_grad_y);

		/// Total Gradient (approximate)
		addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad);

		Bitmap^ bmpImg;
		Imaging::PixelFormat imgFormat;

		// We have to convert the grayscale image back to color so that we can
		// display it in our window. Mat object will have three channels but the displayed image 
		// will still be grayscale image
		Mat imgColor;

		cvtColor(grad, imgColor, cv::COLOR_GRAY2RGB, 3);

		imgFormat = Imaging::PixelFormat::Format24bppRgb;

		bmpImg = gcnew Bitmap(imgColor.cols, imgColor.rows, imgColor.step1(), imgFormat, (IntPtr)imgColor.data);

		// The Bitmap is by default (objects are passed by reference) passed to a picture box by a reference.
		// The 'frame' variable goes out of scope when the function returns. Thus, the pointer is dead, and 
		// you have a GDI object with a pointer to garbage data.
		bmpSobel = gcnew Bitmap(bmpImg);

		panel_Sobel->BackgroundImage = bmpSobel;

		textBox_Sobel->Text =	"In a very general sense, convolution is an operation between every part of an imageand an operator (kernel). " +
								"A kernel is essentially a fixed size array of numerical coefficeints along with an anchor point in that array, " +
								"which is tipically located at the center. Assume you want to know the resulting value of a particular location in " +
								"the image. The value of the convolution is calculated in the following way: " +
								"1. Place the kernel anchor on top of a determined pixel, with the rest of the kernel overlaying the corresponding " +
								"   local pixels in the image." +
								"2. Multiply the kernel coefficients by the corresponding image pixel values and sum the result. " +
								"3. Place the result to the location of the anchor in the input image. " +
								"4. Repeat the process for all pixels by scanning the kernel over the entire image. " +
								"One of the most important convolutions is the computation of derivatives in an image (or an approximation to them). " +
								"in an edge, the pixel intensity changes in a notorious way.A good way to express changes is by using derivatives. " +
								"A high change in gradient indicates a major change in the image.";
	}
	// catch Opencv related exceptions
	catch (cv::Exception ex) {
		// Show the OpenCV exception in a message box
		std::string test = ex.msg;

		System::String^ verwString = marshal_as<System::String^>(test);

		MessageBox::Show("OpenCV exception: " + verwString);
	}
	// catch System related exceptions
	catch (System::Exception ^ exception) {

		// Show the Window exception in a message box
		MessageBox::Show("Windows exception: " + exception->Message);
	}
}

System::Void OpenCVCPP::Hauptfenster::Button_VisualizeDFT_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	// Marshal.StringToHGlobalAnsi(String) Method Copies the contents of a managed String into unmanaged memory,
	// converting into ANSI format as it copies. StringToHGlobalAnsi copies the contents of a managed String 
	// object into native heap, and then converts it into American National Standards Institute (ANSI) format 
	// on the fly. This method allocates the required native heap memory. The following function takes a managed
	// string type and returns a char pointer which can be used like a string (old C type string) in opencv imread() method
	char* convertedFileName = convertManagedStringToANSIFormat(imgFileName);

	// Try to open the data if fails catch exceptions
	try {

		/*
		*/

		// Read an image and crate a Mat object
		// you can only take the Dicreet Fourier Transform of a grayscale image
		// For color images you have to split the image and store each image in a seperate Mat object
		// Then you can take the DFT of each image.
		cvImg = imread(convertedFileName, cv::IMREAD_GRAYSCALE);

		cvImg.type();

		//Console::WriteLine(ty.c_str());

		// Resizing the image so that cvImgResized.cols is divisible by 4
		Mat cvImgResized = resizeMatImageObject(cvImg, 4);

		Mat cvImgResizedFloat;

		// We need to set up our data properly for discreet fourier transform
		// We need to use floating point values because our range needs to be between 0 and 1
		// Right now the image is a grayscale image of unsigned integer type 8 therefore
		// our values will be between 0 and 255. We need to do a conversion:
		cvImgResized.convertTo(cvImgResizedFloat, CV_32FC1, 1.0 / 255.0);

		// Discreet Fourier Transform will produce a complex result with a real and a leteral (so called imaginary) component
		// We will need a Mat object with two channels that can hold both real and leteral (imaginary) components
		Mat cvImgDFT;

		cvImgDFT = createDiscreetFourierTransformObject(cvImgResizedFloat);

		Mat cvImgDFTLogNorm;

		cvImgDFTLogNorm = convertDFTObjectToLogarithmicScaleAndNormalize(cvImgDFT);

		imshow("DFT", cvImgDFTLogNorm);

		Bitmap ^ bmpImg;
		Imaging::PixelFormat imgFormat;

		//// We have to convert the grayscale image back to color so that we can
		//// display it in our window. Mat object will have three channels but the displayed image 
		//// will still be grayscale image
		Mat imgColor;
		//

		//cvtColor(cvImgDFTLogNorm, imgColor, cv::COLOR_GRAY2BGR, 3);

		//imgFormat = Imaging::PixelFormat::Format16bppArgb1555;
		imgFormat = Imaging::PixelFormat::Format24bppRgb;
		//imgFormat = Imaging::PixelFormat::Format64bppPArgb;
		//imgFormat = Imaging::PixelFormat::Format1bppIndexed;
		imgFormat = Imaging::PixelFormat::Format32bppPArgb;

		int test = cvImgDFTLogNorm.step1();
		int csize = cvImgDFTLogNorm.channels();

		bmpImg = gcnew Bitmap(cvImgDFTLogNorm.cols, cvImgDFTLogNorm.rows, 4 * cvImgDFTLogNorm.step1(), imgFormat, (IntPtr)cvImgDFTLogNorm.data);
		//bmpImg = gcnew Bitmap(imgColor.cols, imgColor.rows, 4*imgColor.step1(), imgFormat, (IntPtr)imgColor.data);

		// The Bitmap is by default (objects are passed by reference) passed to a picture box by a reference.
		// The 'frame' variable goes out of scope when the function returns. Thus, the pointer is dead, and 
		// you have a GDI object with a pointer to garbage data.
		bmpVisualizeDFT = gcnew Bitmap(bmpImg);

		panel_VisualizeDFT->BackgroundImage = bmpVisualizeDFT;

		textBox_VisualizeDFT->Text =	"The Fourier Transform will decompose an image into its sinus and cosines components. " +
										"In other words, it will transform an image from its spatial domain to its frequency domain. " +
										"The idea is that any function may be approximated exactly with the sum of infinite sinusand " +
										"cosines functions. The result of the transformation is complex numbers. Displaying this is " +
										"possible either via a real image and a complex image or via a magnitude and a phase image. " +
										"However, throughout the image processing algorithms only the magnitude image is interesting " +
										"as this contains all the information we need about the images geometric structure. Nevertheless, " +
										"if you intend to make some modifications of the image in these forms and then you need to retransform " +
										"it you'll need to preserve both of these.";
	}
	// catch Opencv related exceptions
	catch (cv::Exception ex) {
		// Show the OpenCV exception in a message box
		std::string test = ex.msg;

		System::String^ verwString = marshal_as<System::String^>(test);

		MessageBox::Show("OpenCV exception: " + verwString);
	}
	// catch System related exceptions
	catch (System::Exception ^ exception) {

		// Show the Window exception in a message box
		MessageBox::Show("Windows exception: " + exception->Message);
	}
}

System::Void OpenCVCPP::Hauptfenster::Button_RecenterDFT_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	// Marshal.StringToHGlobalAnsi(String) Method Copies the contents of a managed String into unmanaged memory,
	// converting into ANSI format as it copies. StringToHGlobalAnsi copies the contents of a managed String 
	// object into native heap, and then converts it into American National Standards Institute (ANSI) format 
	// on the fly. This method allocates the required native heap memory. The following function takes a managed
	// string type and returns a char pointer which can be used like a string (old C type string) in opencv imread() method
	char* convertedFileName = convertManagedStringToANSIFormat(imgFileName);

	// Try to open the data if fails catch exceptions
	try {

		/*
		*/

		// Read an image and crate a Mat object
		// you can only take the Dicreet Fourier Transform of a grayscale image
		// For color images you have to split the image and store each image in a seperate Mat object
		// Then you can take the DFT of each image.
		cvImg = imread(convertedFileName, cv::IMREAD_GRAYSCALE);

		// Resizing the image so that cvImgResized.cols is divisible by 4
		Mat cvImgResized = resizeMatImageObject(cvImg, 4);

		Mat cvImgResizedFloat;

		// We need to set up our data properly for discreet fourier transform
		// We need to use floating point values because our range needs to be between 0 and 1
		// Right now the image is a grayscale image of unsigned integer type 8 therefore
		// our values will be between 0 and 255. We need to do a conversion:
		cvImgResized.convertTo(cvImgResizedFloat, CV_32FC1, 1.0 / 255.0);

		// Discreet Fourier Transform will produce a complex result with a real and a leteral (so called imaginary) component
		// We will need a Mat object with two channels that can hold both real and leteral (imaginary) components
		Mat cvImgDFT;

		cvImgDFT = createDiscreetFourierTransformObject(cvImgResizedFloat);

		Mat cvImgDFTLogNorm;

		cvImgDFTLogNorm = convertDFTObjectToLogarithmicScaleAndNormalize(cvImgDFT);

		Mat cvImgDFTRecentered;

		cvImgDFTRecentered = recenterDiscreetFourierTransformObject(cvImgDFTLogNorm);

		imshow("DFT Recentered", cvImgDFTRecentered);

		Bitmap ^ bmpImg;
		Imaging::PixelFormat imgFormat;

		//// We have to convert the grayscale image back to color so that we can
		//// display it in our window. Mat object will have three channels but the displayed image 
		//// will still be grayscale image
		Mat imgColor;
		//

		cvtColor(cvImgDFTRecentered, imgColor, cv::COLOR_GRAY2BGR, 3);

		//imgFormat = Imaging::PixelFormat::Format16bppArgb1555;
		//imgFormat = Imaging::PixelFormat::Format24bppRgb;
		imgFormat = Imaging::PixelFormat::Format24bppRgb;

		//bmpImg = gcnew Bitmap(cvImgDFTLogNorm.cols, cvImgDFTLogNorm.rows, cvImgDFTLogNorm.step1(), imgFormat, (IntPtr)cvImgDFTLogNorm.data);
		bmpImg = gcnew Bitmap(imgColor.cols, imgColor.rows, imgColor.step1(), imgFormat, (IntPtr)imgColor.data);

		// The Bitmap is by default (objects are passed by reference) passed to a picture box by a reference.
		// The 'frame' variable goes out of scope when the function returns. Thus, the pointer is dead, and 
		// you have a GDI object with a pointer to garbage data.
		bmpRecenterDFT = gcnew Bitmap(bmpImg);

		panel_RecenterDFT->BackgroundImage = bmpRecenterDFT;

		textBox_RecenterDFT->Text = "For visualization purposes, the quadrants of the result are rearranged, " +
									"so that the origin(zero, zero) corresponds with the image center.";
	}
	// catch Opencv related exceptions
	catch (cv::Exception ex) {
		// Show the OpenCV exception in a message box
		std::string test = ex.msg;

		System::String^ verwString = marshal_as<System::String^>(test);

		MessageBox::Show("OpenCV exception: " + verwString);
	}
	// catch System related exceptions
	catch (System::Exception ^ exception) {

		// Show the Window exception in a message box
		MessageBox::Show("Windows exception: " + exception->Message);
	}
}

System::Void OpenCVCPP::Hauptfenster::Button_InvertDFT_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	// Marshal.StringToHGlobalAnsi(String) Method Copies the contents of a managed String into unmanaged memory,
	// converting into ANSI format as it copies. StringToHGlobalAnsi copies the contents of a managed String 
	// object into native heap, and then converts it into American National Standards Institute (ANSI) format 
	// on the fly. This method allocates the required native heap memory. The following function takes a managed
	// string type and returns a char pointer which can be used like a string (old C type string) in opencv imread() method
	char* convertedFileName = convertManagedStringToANSIFormat(imgFileName);

	// Try to open the data if fails catch exceptions
	try {

		/*
		*/

		// Read an image and crate a Mat object
		// you can only take the Dicreet Fourier Transform of a grayscale image
		// For color images you have to split the image and store each image in a seperate Mat object
		// Then you can take the DFT of each image.
		cvImg = imread(convertedFileName, cv::IMREAD_GRAYSCALE);

		// Resizing the image so that cvImgResized.cols is divisible by 4
		Mat cvImgResized = resizeMatImageObject(cvImg, 4);

		Mat cvImgResizedFloat;

		// We need to set up our data properly for discreet fourier transform
		// We need to use floating point values because our range needs to be between 0 and 1
		// Right now the image is a grayscale image of unsigned integer type 8 therefore
		// our values will be between 0 and 255. We need to do a conversion:
		cvImgResized.convertTo(cvImgResizedFloat, CV_32FC1, 1.0 / 255.0);

		// Discreet Fourier Transform will produce a complex result with a real and a leteral (so called imaginary) component
		// We will need a Mat object with two channels that can hold both real and leteral (imaginary) components
		Mat cvImgDFT;

		cvImgDFT = createDiscreetFourierTransformObject(cvImgResizedFloat);

		Mat cvImgDFTInverted;

		cvImgDFTInverted = invertDiscreetFourierTransformObject(cvImgDFT);

		imshow("DFT Inverted", cvImgDFTInverted);

		Bitmap ^ bmpImg;
		Imaging::PixelFormat imgFormat;

		//// We have to convert the grayscale image back to color so that we can
		//// display it in our window. Mat object will have three channels but the displayed image 
		//// will still be grayscale image
		//Mat imgColor;
		//

		//cvtColor(cvImgDFTRecentered, imgColor, cv::COLOR_GRAY2BGR, 3);

		//imgFormat = Imaging::PixelFormat::Format16bppArgb1555;
		//imgFormat = Imaging::PixelFormat::Format24bppRgb;
		imgFormat = Imaging::PixelFormat::Format32bppRgb;

		bmpImg = gcnew Bitmap(cvImgDFTInverted.cols, cvImgDFTInverted.rows, 4 * cvImgDFTInverted.step1(), imgFormat, (IntPtr)cvImgDFTInverted.data);
		//bmpImg = gcnew Bitmap(imgColor.cols, imgColor.rows, imgColor.step1(), imgFormat, (IntPtr)imgColor.data);

		// The Bitmap is by default (objects are passed by reference) passed to a picture box by a reference.
		// The 'frame' variable goes out of scope when the function returns. Thus, the pointer is dead, and 
		// you have a GDI object with a pointer to garbage data.
		bmpInvertDFT = gcnew Bitmap(bmpImg);

		panel_InvertDFT->BackgroundImage = bmpInvertDFT;

		textBox_InvertDFT->Text = "Inversion takes the image in frequency domain back to spacial domain, once the image is in frequency domain, " +
								  "many different type of processing can be applied. For example removing different ferquencies, bluring. " +
								  "or sharpening the image etc. We can use frequency domain to remove noise from an image. We can also use fourier " +
								  " to recognize letters and numbers. TransformThe image can also be inverted. ";
	}
	// catch Opencv related exceptions
	catch (cv::Exception ex) {
		// Show the OpenCV exception in a message box
		std::string test = ex.msg;

		System::String^ verwString = marshal_as<System::String^>(test);

		MessageBox::Show("OpenCV exception: " + verwString);
	}
	// catch System related exceptions
	catch (System::Exception ^ exception) {

		// Show the Window exception in a message box
		MessageBox::Show("Windows exception: " + exception->Message);
	}
}

System::Void OpenCVCPP::Hauptfenster::Button_CreateHistogram_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	// Marshal.StringToHGlobalAnsi(String) Method Copies the contents of a managed String into unmanaged memory,
	// converting into ANSI format as it copies. StringToHGlobalAnsi copies the contents of a managed String 
	// object into native heap, and then converts it into American National Standards Institute (ANSI) format 
	// on the fly. This method allocates the required native heap memory. The following function takes a managed
	// string type and returns a char pointer which can be used like a string (old C type string) in opencv imread() method
	char* convertedFileName = convertManagedStringToANSIFormat(imgFileName);

	// Try to open the data if fails catch exceptions
	try {
		// Read image and crate a Mat object
		cvImg = imread(convertedFileName, cv::IMREAD_UNCHANGED);

		// cvImg.channels() returns the number of channels each picture has
		if (cvImg.channels() >= 3) {

			// Resizing the image so that cvImgResized.cols is divisible by 4
			Mat cvImgResized = resizeMatImageObject(cvImg, 4);

			// Separate image in BRG
			vector<Mat> bgr;
			split(cvImgResized, bgr);

			// Create the histogram for 256 bins
			// The number of possibles values
			int numbins = 256;

			/// Set the ranges ( for B,G,R) )
			float range[] = { 0, 256 };
			const float* histRange = { range };

			Mat b_hist, g_hist, r_hist;

			calcHist(&bgr[0], 1, 0, Mat(), b_hist, 1, &numbins, &histRange);
			calcHist(&bgr[1], 1, 0, Mat(), g_hist, 1, &numbins, &histRange);
			calcHist(&bgr[2], 1, 0, Mat(), r_hist, 1, &numbins, &histRange);

			// Draw the histogram
			// We go to draw lines for each channel
			int width = 512;
			int height = 300;
			// Create image with gray base
			Mat histImage(height, width, CV_8UC3, Scalar(20, 20, 20));

			// Normalize the histograms to height of image
			normalize(b_hist, b_hist, 0, height, NORM_MINMAX);
			normalize(g_hist, g_hist, 0, height, NORM_MINMAX);
			normalize(r_hist, r_hist, 0, height, NORM_MINMAX);

			// Draw the histogram
			int binStep = cvRound((float)width / (float)numbins);
			for (int i = 1; i < numbins; i++)
			{
				line(histImage,
					cv::Point(binStep * (i - 1), height - cvRound(b_hist.at<float>(i - 1))),
					cv::Point(binStep * (i), height - cvRound(b_hist.at<float>(i))),
					Scalar(255, 0, 0)
				);
				line(histImage,
					cv::Point(binStep * (i - 1), height - cvRound(g_hist.at<float>(i - 1))),
					cv::Point(binStep * (i), height - cvRound(g_hist.at<float>(i))),
					Scalar(0, 255, 0)
				);
				line(histImage,
					cv::Point(binStep * (i - 1), height - cvRound(r_hist.at<float>(i - 1))),
					cv::Point(binStep * (i), height - cvRound(r_hist.at<float>(i))),
					Scalar(0, 0, 255)
				);
			}

			int type_0 = histImage.type();
			int depth_0 = histImage.depth();
			int cahannels_0 = histImage.channels();

			Bitmap ^ bmpImg;
			Imaging::PixelFormat imgFormat;

			imgFormat = Imaging::PixelFormat::Format24bppRgb;

			bmpImg = gcnew Bitmap(histImage.cols, histImage.rows, histImage.step1(), imgFormat, (IntPtr)histImage.data);

			// The Bitmap is by default (objects are passed by reference) passed to a picture box by a reference.
			// The 'frame' variable goes out of scope when the function returns. Thus, the pointer is dead, and 
			// you have a GDI object with a pointer to garbage data.
			bmpShowHistogram = gcnew Bitmap(bmpImg);

			panel_CreateHistogram->BackgroundImage = bmpShowHistogram;

			textBox_CreateHistogram->Text = "A histogram is a statistical graphic representation of variable distribution that allows us to " +
											"understand the density estimation and probability distribution of data. A histogram is created by " +
											"dividing the entire range of variable values into a small range of values, and then counting how " +
											"many values fall into each interval.If we apply this histogram concept to an image, it seems to " +
											"be difficult to understand but, in fact, it is very simple.In a gray image, our variable values' " +
											"ranges are each possible gray value (from 0 to 255), and the density is the number of pixels of the " +
											"image that have this value. This means that we have to count the number of pixels of the image that " +
											"have a value of 0, the number of pixels with a value of 1, and so on.";
		}
		else {
			MessageBox::Show("Histogram functionality is implemented only for images with R G B channels (Min 3 Channel).");
		}
	}
	// catch Opencv related exceptions
	catch (cv::Exception ex) {
		// Show the OpenCV exception in a message box
		std::string test = ex.msg;

		System::String^ verwString = marshal_as<System::String^>(test);

		MessageBox::Show("OpenCV exception: " + verwString);
	}
	// catch System related exceptions
	catch (System::Exception ^ exception) {

		// Show the Window exception in a message box
		MessageBox::Show("Windows exception: " + exception->Message);
	}

	return System::Void();
}

System::Void OpenCVCPP::Hauptfenster::Button_EqualizeImageColor_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	// Marshal.StringToHGlobalAnsi(String) Method Copies the contents of a managed String into unmanaged memory,
	// converting into ANSI format as it copies. StringToHGlobalAnsi copies the contents of a managed String 
	// object into native heap, and then converts it into American National Standards Institute (ANSI) format 
	// on the fly. This method allocates the required native heap memory. The following function takes a managed
	// string type and returns a char pointer which can be used like a string (old C type string) in opencv imread() method
	char* convertedFileName = convertManagedStringToANSIFormat(imgFileName);

	// Try to open the data if fails catch exceptions
	try {
		// Read image and crate a Mat object
		cvImg = imread(convertedFileName, cv::IMREAD_UNCHANGED);

		// cvImg.channels() returns the number of channels each picture has
		if (cvImg.channels() >= 3) {

			// Resizing the image so that cvImgResized.cols is divisible by 4
			Mat cvImgResized = resizeMatImageObject(cvImg, 4);

			Mat result;
			// Convert BGR image to YCbCr
			Mat ycrcb;
			cvtColor(cvImgResized, ycrcb, COLOR_BGR2YCrCb);

			// Split image into channels
			vector<Mat> channels;
			split(ycrcb, channels);

			// Equalize the Y channel only
			equalizeHist(channels[0], channels[0]);

			// Merge the result channels
			merge(channels, ycrcb);

			// Convert color ycrcb to BGR
			cvtColor(ycrcb, result, COLOR_YCrCb2BGR);

			// Show result
			Bitmap^ bmpImg;
			Imaging::PixelFormat imgFormat;

			imgFormat = Imaging::PixelFormat::Format24bppRgb;

			bmpImg = gcnew Bitmap(result.cols, result.rows, result.step1(), imgFormat, (IntPtr)result.data);

			// The Bitmap is by default (objects are passed by reference) passed to a picture box by a reference.
			// The 'frame' variable goes out of scope when the function returns. Thus, the pointer is dead, and 
			// you have a GDI object with a pointer to garbage data.
			bmpShowHistogram = gcnew Bitmap(bmpImg);

			//panel1->BackgroundImage = bmpImg;
			panel_EqualizeImageColor->BackgroundImage = bmpShowHistogram;
		}
		else {
			MessageBox::Show("Equalize effect functionality is implemented only for images with R G B channels. Please load an image with minimum 3 channels.");
		}
	}
	// catch Opencv related exceptions
	catch (cv::Exception ex) {
		// Show the OpenCV exception in a message box
		std::string test = ex.msg;

		System::String^ verwString = marshal_as<System::String^>(test);

		MessageBox::Show("OpenCV exception: " + verwString);
	}
	// catch System related exceptions
	catch (System::Exception ^ exception) {

		// Show the Window exception in a message box
		MessageBox::Show("Windows exception: " + exception->Message);
	}

	return System::Void();
}

System::Void OpenCVCPP::Hauptfenster::Button_LomographyEffect_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	// Marshal.StringToHGlobalAnsi(String) Method Copies the contents of a managed String into unmanaged memory,
	// converting into ANSI format as it copies. StringToHGlobalAnsi copies the contents of a managed String 
	// object into native heap, and then converts it into American National Standards Institute (ANSI) format 
	// on the fly. This method allocates the required native heap memory. The following function takes a managed
	// string type and returns a char pointer which can be used like a string (old C type string) in opencv imread() method
	char* convertedFileName = convertManagedStringToANSIFormat(imgFileName);

	// Try to open the data if fails catch exceptions
	try {

		// Read image and crate a Mat object
		cvImg = imread(convertedFileName, cv::IMREAD_UNCHANGED);

		if (cvImg.channels() >= 4) {
			// Read image as IMREAD_COLOR and crate a Mat object with 3 channels instead of 4 (because you are loading a png file)
			cvImg = imread(convertedFileName, cv::IMREAD_COLOR);
		}

		// cvImg.channels() returns the number of channels each picture has
		if (cvImg.channels() >= 3) {

			// Resizing the image so that cvImgResized.cols is divisible by 4
			Mat cvImgResized = resizeMatImageObject(cvImg, 4);

			Mat result;

			const double E = std::exp(1.0);
			// Create Lookup table for color curve effect
			Mat lut(1, 256, CV_8UC1);
			for (int i = 0; i < 256; i++)
			{
				float x = (float)i / 256.0;
				lut.at<uchar>(i) = cvRound(256 * (1 / (1 + pow(E, -((x - 0.5) / 0.1)))));
			}

			// Split the image channels and apply curve transform only to red channel
			vector<Mat> bgr;
			split(cvImgResized, bgr);
			LUT(bgr[2], lut, bgr[2]);
			// merge result
			merge(bgr, result);

			// Create image for halo dark
			Mat halo(cvImgResized.rows, cvImgResized.cols, CV_32FC3, Scalar(0.3, 0.3, 0.3));
			// Create circle 
			circle(halo, cv::Point(cvImgResized.cols / 2, cvImgResized.rows / 2), cvImgResized.cols / 3, Scalar(1, 1, 1), -1);
			blur(halo, halo, cv::Size(cvImgResized.cols / 3, cvImgResized.cols / 3));

			// Convert the result to float to allow multiply by 1 factor
			Mat resultf;
			result.convertTo(resultf, CV_32FC3);

			// Multiply our result with halo
			multiply(resultf, halo, resultf);

			// convert to 8 bits
			resultf.convertTo(result, CV_8UC3);

			// Release mat memory
			halo.release();
			resultf.release();
			lut.release();
			bgr[0].release();
			bgr[1].release();
			bgr[2].release();

			// Show result
			Bitmap ^ bmpImg;
			Imaging::PixelFormat imgFormat;

			imgFormat = Imaging::PixelFormat::Format24bppRgb;

			bmpImg = gcnew Bitmap(result.cols, result.rows, result.step1(), imgFormat, (IntPtr)result.data);

			// The Bitmap is by default (objects are passed by reference) passed to a picture box by a reference.
			// The 'frame' variable goes out of scope when the function returns. Thus, the pointer is dead, and 
			// you have a GDI object with a pointer to garbage data.
			bmpLomography = gcnew Bitmap(bmpImg);

			panel_LomographyFilter->BackgroundImage = bmpLomography;
		}
		else {
			MessageBox::Show("Lomography effect functionality is implemented only for images with R G B channels. Please load an image with minimum 3 channels.");
		}
	}
	// catch Opencv related exceptions
	catch (cv::Exception ex) {
		// Show the OpenCV exception in a message box
		std::string test = ex.msg;

		System::String^ verwString = marshal_as<System::String^>(test);

		MessageBox::Show("OpenCV exception: " + verwString);
	}
	// catch System related exceptions
	catch (System::Exception ^ exception) {

		// Show the Window exception in a message box
		MessageBox::Show("Windows exception: " + exception->Message);
	}

	return System::Void();
}

System::Void OpenCVCPP::Hauptfenster::Button_CartoonizeEffect_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	// Marshal.StringToHGlobalAnsi(String) Method Copies the contents of a managed String into unmanaged memory,
	// converting into ANSI format as it copies. StringToHGlobalAnsi copies the contents of a managed String 
	// object into native heap, and then converts it into American National Standards Institute (ANSI) format 
	// on the fly. This method allocates the required native heap memory. The following function takes a managed
	// string type and returns a char pointer which can be used like a string (old C type string) in opencv imread() method
	char* convertedFileName = convertManagedStringToANSIFormat(imgFileName);

	// Try to open the data if fails catch exceptions
	try {

		// Read image and crate a Mat object
		cvImg = imread(convertedFileName, cv::IMREAD_UNCHANGED);

		if (cvImg.channels() >= 4) {
			// Read image as IMREAD_COLOR and crate a Mat object with 3 channels instead of 4 (because you are loading a png file)
			cvImg = imread(convertedFileName, cv::IMREAD_COLOR);
		}

		// cvImg.channels() returns the number of channels each picture has
		if (cvImg.channels() >= 3) {

			// Resizing the image so that cvImgResized.cols is divisible by 4
			Mat cvImgResized = resizeMatImageObject(cvImg, 4);

			/** EDGES **/
			// Apply median filter to remove possible noise
			Mat imgMedian;
			medianBlur(cvImgResized, imgMedian, 7);

			// Detect edges with canny
			Mat imgCanny;
			Canny(imgMedian, imgCanny, 50, 150);

			// Dilate the edges
			Mat kernel = getStructuringElement(MORPH_RECT, cv::Size(2, 2));
			dilate(imgCanny, imgCanny, kernel);

			// Scale edges values to 1 and invert values
			imgCanny = imgCanny / 255;
			imgCanny = 1 - imgCanny;

			// Use float values to allow multiply between 0 and 1
			Mat imgCannyf;
			imgCanny.convertTo(imgCannyf, CV_32FC3);

			// Blur the edgest to do smooth effect
			blur(imgCannyf, imgCannyf, cv::Size(5, 5));

			/** COLOR **/
			// Apply bilateral filter to homogenizes color
			Mat imgBF;
			bilateralFilter(cvImgResized, imgBF, 9, 150.0, 150.0);

			// truncate colors
			Mat result = imgBF / 25;
			result = result * 25;

			/** MERGES COLOR + EDGES **/
			// Create a 3 channles for edges
			Mat imgCanny3c;
			Mat cannyChannels[] = { imgCannyf, imgCannyf, imgCannyf };
			merge(cannyChannels, 3, imgCanny3c);

			// Convert color result to float 
			Mat resultf;
			result.convertTo(resultf, CV_32FC3);

			// Multiply color and edges matrices
			multiply(resultf, imgCanny3c, resultf);

			// convert to 8 bits color
			resultf.convertTo(result, CV_8UC3);

			// Show result
			Bitmap^ bmpImg;
			Imaging::PixelFormat imgFormat;

			imgFormat = Imaging::PixelFormat::Format24bppRgb;

			bmpImg = gcnew Bitmap(result.cols, result.rows, result.step1(), imgFormat, (IntPtr)result.data);

			// The Bitmap is by default (objects are passed by reference) passed to a picture box by a reference.
			// The 'frame' variable goes out of scope when the function returns. Thus, the pointer is dead, and 
			// you have a GDI object with a pointer to garbage data.
			bmpCartoonize = gcnew Bitmap(bmpImg);

			panel_CartoonizeEffect->BackgroundImage = bmpCartoonize;
		}
		else {
			MessageBox::Show("Cartoonize effect functionality is implemented only for images with R G B channels. Please load an image with minimum 3 channels.");
		}
	}
	// catch Opencv related exceptions
	catch (cv::Exception ex) {
		// Show the OpenCV exception in a message box
		std::string test = ex.msg;

		System::String^ verwString = marshal_as<System::String^>(test);

		MessageBox::Show("OpenCV exception: " + verwString);
	}
	// catch System related exceptions
	catch (System::Exception ^ exception) {

		// Show the Window exception in a message box
		MessageBox::Show("Windows exception: " + exception->Message);
	}

	return System::Void();
}

System::Void OpenCVCPP::Hauptfenster::Button_NoiseRemoval_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	// Marshal.StringToHGlobalAnsi(String) Method Copies the contents of a managed String into unmanaged memory,
	// converting into ANSI format as it copies. StringToHGlobalAnsi copies the contents of a managed String 
	// object into native heap, and then converts it into American National Standards Institute (ANSI) format 
	// on the fly. This method allocates the required native heap memory. The following function takes a managed
	// string type and returns a char pointer which can be used like a string (old C type string) in opencv imread() method
	char* convertedFileName = convertManagedStringToANSIFormat(imgFileName);

	// Try to open the data if fails catch exceptions
	try {

		if (checkBox_ImgProcessingMedianBlur->Checked == true || checkBox_ImgProcessingBlur->Checked == true) {

			// Read image as grayscale and crate a Mat object
			cvImg = imread(convertedFileName, cv::IMREAD_GRAYSCALE);

			//// cvImg.channels() returns the number of channels each picture has
			//// if the image is already grayscale, there is not need to perform
			//// grayscale filtering/conversion
			//if (cvImg.channels() == 1) {

			//	cvImg = imread(convertedFileName, cv::IMREAD_GRAYSCALE);
			//}

			// Resizing the image so that cvImgResized.cols is divisible by 4
			Mat cvImgResized = resizeMatImageObject(cvImg, 4);

			// Remove noise
			Mat img_noise, img_box_smooth;

			medianBlur(cvImgResized, img_noise, 3);

			blur(cvImgResized, img_box_smooth, cv::Size(trackBar_NoiseRemovalIndex->Value, trackBar_NoiseRemovalIndex->Value));

			// Show result
			Bitmap^ bmpImg;
			Imaging::PixelFormat imgFormat;

			imgFormat = Imaging::PixelFormat::Format24bppRgb;

			Mat color;

			if (checkBox_ImgProcessingMedianBlur->Checked == true) {

				cvtColor(img_noise, color, cv::COLOR_GRAY2RGB, 3);
			}
			else if (checkBox_ImgProcessingBlur->Checked == true) {

				cvtColor(img_box_smooth, color, cv::COLOR_GRAY2RGB, 3);
			}

			bmpImg = gcnew Bitmap(color.cols, color.rows, color.step1(), imgFormat, (IntPtr)color.data);

			// The Bitmap is by default (objects are passed by reference) passed to a picture box by a reference.
			// The 'frame' variable goes out of scope when the function returns. Thus, the pointer is dead, and 
			// you have a GDI object with a pointer to garbage data.
			bmpNoiseRemoval = gcnew Bitmap(bmpImg);

			panel_NoiseRemoval->BackgroundImage = bmpNoiseRemoval;
		}
		else {
			MessageBox::Show("Please select one of median blur or blur checkboxes!");
		}
	}
	// catch Opencv related exceptions
	catch (cv::Exception ex) {
		// Show the OpenCV exception in a message box
		std::string test = ex.msg;

		System::String^ verwString = marshal_as<System::String^>(test);

		MessageBox::Show("OpenCV exception: " + verwString);
	}
	// catch System related exceptions
	catch (System::Exception ^ exception) {

		// Show the Window exception in a message box
		MessageBox::Show("Windows exception: " + exception->Message);
	}

	return System::Void();
}

System::Void OpenCVCPP::Hauptfenster::trackBar_NoiseRemovalIndex_Scroll(System::Object ^ sender, System::EventArgs ^ e)
{
	label_NoiseRemoval->Text = trackBar_NoiseRemovalIndex->Value.ToString();
}

System::Void OpenCVCPP::Hauptfenster::Button_RemoveLightAndThreshold_Click(System::Object^ sender, System::EventArgs^ e)
{
	// Marshal.StringToHGlobalAnsi(String) Method Copies the contents of a managed String into unmanaged memory,
	// converting into ANSI format as it copies. StringToHGlobalAnsi copies the contents of a managed String 
	// object into native heap, and then converts it into American National Standards Institute (ANSI) format 
	// on the fly. This method allocates the required native heap memory. The following function takes a managed
	// string type and returns a char pointer which can be used like a string (old C type string) in opencv imread() method
	char* convertedFileName = convertManagedStringToANSIFormat(imgFileName);
	char* convertedLightPatternFileName = convertManagedStringToANSIFormat(imgLightPatternFileName);

	// Try to open the data if fails catch exceptions
	try {

		// Read image and crate a Mat object
		cvImg = imread(convertedFileName, cv::IMREAD_GRAYSCALE);
		Mat cvImgLightPattern = imread(convertedFileName, cv::IMREAD_GRAYSCALE);

		// Resizing the image so that cvImgResized.cols is divisible by 4
		Mat cvImgResized = resizeMatImageObject(cvImg, 4);
		Mat cvImgResizedLightPattern = resizeMatImageObject(cvImg, 4);

		// ----------------------------------------------------------------------------------------------------
		// 1. Process:
		// Image to be processed should already be loaded to the main window.

		// Creating the variables in order to show the results
		Bitmap^ bmpImg;
		Imaging::PixelFormat imgFormat;
		imgFormat = Imaging::PixelFormat::Format24bppRgb;

		// ----------------------------------------------------------------------------------------------------
		// 2. Process:
		// Processing image from previous state where image is loaded
		// Remove noise by applying medianblur size 3 to the image
		Mat img_noise;

		medianBlur(cvImgResized, img_noise, 3);

		// ----------------------------------------------------------------------------------------------------
		// 3. Process:
		// Processing image from previous state where median blur is applied to the original image
		// Calculate light pattern
		// Basic and effective way to calculate the light pattern from one image using blur
		// blur(img, pattern, cv::Size(img.cols / 3, img.cols / 3));
		cvImgResizedLightPattern = calculateLightPattern(img_noise);

		// ----------------------------------------------------------------------------------------------------
		// 4. Process:
		// Processing image from previous state where light pattern is calculated
		// Apply the light pattern
		Mat img_no_light;
		img_noise.copyTo(img_no_light);
		int method_light = 0;
		if (checkBox_Method_Normalize_i->Checked == true) {
			method_light = 1;
		}

		img_no_light = removeLight(img_noise, cvImgResizedLightPattern, method_light);

		// ----------------------------------------------------------------------------------------------------
		// 5. Process:
		// Processing image from previous state where light pattern is removed from the image.
		// The following code binarize image for segmentation stage
		// Binarize image for segmentation algorithms
		Mat img_thr;

		threshold(img_no_light, img_thr, 30, 255, THRESH_BINARY);
		//threshold(img_no_light, img_thr, 140, 255, THRESH_BINARY_INV);

		Mat color;

		cvtColor(img_thr, color, cv::COLOR_GRAY2RGB, 3);

		// Show result
		imgFormat = Imaging::PixelFormat::Format24bppRgb;

		bmpImg = gcnew Bitmap(color.cols, color.rows, color.step1(), imgFormat, (IntPtr)color.data);

		// The Bitmap is by default (objects are passed by reference) passed to a picture box by a reference.
		// The 'frame' variable goes out of scope when the function returns. Thus, the pointer is dead, and 
		// you have a GDI object with a pointer to garbage data.
		bmpThreshold = gcnew Bitmap(bmpImg);

		panel_RemoveLightAndThreshold->BackgroundImage = bmpThreshold;
	}
	// catch Opencv related exceptions
	catch (cv::Exception ex) {
		// Show the OpenCV exception in a message box
		std::string test = ex.msg;

		System::String^ verwString = marshal_as<System::String^>(test);

		MessageBox::Show("OpenCV exception: " + verwString);
	}
	// catch System related exceptions
	catch (System::Exception ^ exception) {

		// Show the Window exception in a message box
		MessageBox::Show("Windows exception: " + exception->Message);
	}

	return System::Void();
}

System::Void OpenCVCPP::Hauptfenster::Button_ProcessLightPattern_Click(System::Object^ sender, System::EventArgs^ e)
{
	// Marshal.StringToHGlobalAnsi(String) Method Copies the contents of a managed String into unmanaged memory,
	// converting into ANSI format as it copies. StringToHGlobalAnsi copies the contents of a managed String 
	// object into native heap, and then converts it into American National Standards Institute (ANSI) format 
	// on the fly. This method allocates the required native heap memory. The following function takes a managed
	// string type and returns a char pointer which can be used like a string (old C type string) in opencv imread() method
	char* convertedFileName = convertManagedStringToANSIFormat(imgFileName);
	char* convertedLightPatternFileName = convertManagedStringToANSIFormat(imgLightPatternFileName);

	// Try to open the data if fails catch exceptions
	try {

		// Read image and crate a Mat object
		cvImg = imread(convertedFileName, cv::IMREAD_GRAYSCALE);
		Mat cvImgLightPattern = imread(convertedFileName, cv::IMREAD_GRAYSCALE);

		// Resizing the image so that cvImgResized.cols is divisible by 4
		Mat cvImgResized = resizeMatImageObject(cvImg, 4);
		Mat cvImgResizedLightPattern = resizeMatImageObject(cvImg, 4);

		// ----------------------------------------------------------------------------------------------------
		// 1. Process:
		// Show the image to be processed
		Mat color1;

		cvtColor(cvImgResized, color1, cv::COLOR_GRAY2RGB, 3);

		// Show result
		Bitmap^ bmpImg;
		Imaging::PixelFormat imgFormat;

		imgFormat = Imaging::PixelFormat::Format24bppRgb;

		bmpImg = gcnew Bitmap(color1.cols, color1.rows, color1.step1(), imgFormat, (IntPtr)color1.data);

		// The Bitmap is by default (objects are passed by reference) passed to a picture box by a reference.
		// The 'frame' variable goes out of scope when the function returns. Thus, the pointer is dead, and 
		// you have a GDI object with a pointer to garbage data.
		bmpLightPattern_1 = gcnew Bitmap(bmpImg);

		panel_ProcessLightPattern_1->BackgroundImage = bmpLightPattern_1;
		// ----------------------------------------------------------------------------------------------------
		// 2. Process:
		// Processing image from previous state where image is loaded
		// Remove noise by applying medianblur size 3 to the image
		Mat img_noise;

		Mat color2;

		medianBlur(cvImgResized, img_noise, 3);

		cvtColor(img_noise, color2, cv::COLOR_GRAY2RGB, 3);

		// Show result
		imgFormat = Imaging::PixelFormat::Format24bppRgb;

		bmpImg = gcnew Bitmap(color2.cols, color2.rows, color2.step1(), imgFormat, (IntPtr)color2.data);

		// The Bitmap is by default (objects are passed by reference) passed to a picture box by a reference.
		// The 'frame' variable goes out of scope when the function returns. Thus, the pointer is dead, and 
		// you have a GDI object with a pointer to garbage data.
		bmpLightPattern_2 = gcnew Bitmap(bmpImg);

		panel_ProcessLightPattern_2->BackgroundImage = bmpLightPattern_2;
		// ----------------------------------------------------------------------------------------------------
		// 3. Process:
		// Processing image from previous state where median blur is applied to the original image
		// Calculate light pattern
		// Basic and effective way to calculate the light pattern from one image using blur
		// blur(img, pattern, cv::Size(img.cols / 3, img.cols / 3));
		cvImgResizedLightPattern = calculateLightPattern(img_noise);

		Mat color3;

		cvtColor(cvImgResizedLightPattern, color3, cv::COLOR_GRAY2RGB, 3);

		// Show result
		imgFormat = Imaging::PixelFormat::Format24bppRgb;

		bmpImg = gcnew Bitmap(color3.cols, color3.rows, color3.step1(), imgFormat, (IntPtr)color3.data);

		// The Bitmap is by default (objects are passed by reference) passed to a picture box by a reference.
		// The 'frame' variable goes out of scope when the function returns. Thus, the pointer is dead, and 
		// you have a GDI object with a pointer to garbage data.
		bmpLightPattern_3 = gcnew Bitmap(bmpImg);

		panel_ProcessLightPattern_3->BackgroundImage = bmpLightPattern_3;
		// ----------------------------------------------------------------------------------------------------
		// 4. Process:
		// Processing image from previous state where light pattern is calculated
		// Apply the light pattern
		Mat img_no_light;
		img_noise.copyTo(img_no_light);
		int method_light = 0;
		if (checkBox_Method_Normalize_ii->Checked == true) {
			method_light = 1;
		}

		img_no_light = removeLight(img_noise, cvImgResizedLightPattern, method_light);

		//imshow("img_no_light", img_no_light);

		Mat color4;

		cvtColor(img_no_light, color4, cv::COLOR_GRAY2RGB, 3);

		// Show result
		imgFormat = Imaging::PixelFormat::Format24bppRgb;

		bmpImg = gcnew Bitmap(color4.cols, color4.rows, color4.step1(), imgFormat, (IntPtr)color4.data);

		// The Bitmap is by default (objects are passed by reference) passed to a picture box by a reference.
		// The 'frame' variable goes out of scope when the function returns. Thus, the pointer is dead, and 
		// you have a GDI object with a pointer to garbage data.
		bmpLightPattern_4 = gcnew Bitmap(bmpImg);

		panel_ProcessLightPattern_4->BackgroundImage = bmpLightPattern_4;

		// ----------------------------------------------------------------------------------------------------
		// 5. Process:
		// Processing image from previous state where light pattern is removed from the image.
		// The following code binarize image for segmentation stage
		// Binarize image for segmentation algorithms
		Mat img_thr;

		threshold(img_no_light, img_thr, 30, 255, THRESH_BINARY);
		//threshold(img_no_light, img_thr, 140, 255, THRESH_BINARY_INV);

		//imshow("img_no_light", img_no_light);

		Mat color5;

		cvtColor(img_thr, color5, cv::COLOR_GRAY2RGB, 3);

		// Show result
		imgFormat = Imaging::PixelFormat::Format24bppRgb;

		bmpImg = gcnew Bitmap(color5.cols, color2.rows, color5.step1(), imgFormat, (IntPtr)color5.data);

		// The Bitmap is by default (objects are passed by reference) passed to a picture box by a reference.
		// The 'frame' variable goes out of scope when the function returns. Thus, the pointer is dead, and 
		// you have a GDI object with a pointer to garbage data.
		bmpLightPattern_5 = gcnew Bitmap(bmpImg);

		panel_ProcessLightPattern_5->BackgroundImage = bmpLightPattern_5;

	}
	// catch Opencv related exceptions
	catch (cv::Exception ex) {
		// Show the OpenCV exception in a message box
		std::string test = ex.msg;

		System::String^ verwString = marshal_as<System::String^>(test);

		MessageBox::Show("OpenCV exception: " + verwString);
	}
	// catch System related exceptions
	catch (System::Exception ^ exception) {

		// Show the Window exception in a message box
		MessageBox::Show("Windows exception: " + exception->Message);
	}

	return System::Void();
}

System::Void OpenCVCPP::Hauptfenster::Button_RunSegmentationAlgorithms_Click(System::Object^ sender, System::EventArgs^ e)
{
	// Marshal.StringToHGlobalAnsi(String) Method Copies the contents of a managed String into unmanaged memory,
	// converting into ANSI format as it copies. StringToHGlobalAnsi copies the contents of a managed String 
	// object into native heap, and then converts it into American National Standards Institute (ANSI) format 
	// on the fly. This method allocates the required native heap memory. The following function takes a managed
	// string type and returns a char pointer which can be used like a string (old C type string) in opencv imread() method
	char* convertedFileName = convertManagedStringToANSIFormat(imgFileName);
	char* convertedLightPatternFileName = convertManagedStringToANSIFormat(imgLightPatternFileName);

	// Try to open the data if fails catch exceptions
	try {

		// Read image and crate a Mat object
		cvImg = imread(convertedFileName, cv::IMREAD_GRAYSCALE);
		Mat cvImgLightPattern = imread(convertedFileName, cv::IMREAD_GRAYSCALE);

		// Resizing the image so that cvImgResized.cols is divisible by 4
		Mat cvImgResized = resizeMatImageObject(cvImg, 4);
		Mat cvImgResizedLightPattern = resizeMatImageObject(cvImg, 4);

		// ----------------------------------------------------------------------------------------------------
		// 1. Process:
		// Image to be processed should already be loaded to the main window.

		// Creating the variables in order to show the results
		Bitmap^ bmpImg;
		Imaging::PixelFormat imgFormat;
		imgFormat = Imaging::PixelFormat::Format24bppRgb;

		// ----------------------------------------------------------------------------------------------------
		// 2. Process:
		// Processing image from previous state where image is loaded
		// Remove noise by applying medianblur size 3 to the image
		Mat img_noise;

		medianBlur(cvImgResized, img_noise, 3);

		// ----------------------------------------------------------------------------------------------------
		// 3. Process:
		// Processing image from previous state where median blur is applied to the original image
		// Calculate light pattern
		// Basic and effective way to calculate the light pattern from one image using blur
		// blur(img, pattern, cv::Size(img.cols / 3, img.cols / 3));
		cvImgResizedLightPattern = calculateLightPattern(img_noise);

		// ----------------------------------------------------------------------------------------------------
		// 4. Process:
		// Processing image from previous state where light pattern is calculated
		// Apply the light pattern
		Mat img_no_light;
		img_noise.copyTo(img_no_light);
		int method_light = 0;
		if (checkBox_Method_Normalize_iii->Checked == true) {
			method_light = 1;
		}

		img_no_light = removeLight(img_noise, cvImgResizedLightPattern, method_light);

		// ----------------------------------------------------------------------------------------------------
		// 5. Process:
		// Processing image from previous state where light pattern is removed from the image.
		// The following code binarize image for segmentation stage
		// Binarize image for segmentation algorithms
		Mat img_thr;

		threshold(img_no_light, img_thr, 30, 255, THRESH_BINARY);
		//threshold(img_no_light, img_thr, 140, 255, THRESH_BINARY_INV);

		Mat img_connected;
		Mat img_stats;
		Mat img_contours;
		
		img_connected = ConnectedComponents(img_thr);
		//img_stats = ConnectedComponentsStats(img_thr);
		img_contours = FindContoursBasic(img_thr);

		// Show result
		imgFormat = Imaging::PixelFormat::Format24bppRgb;

		bmpImg = gcnew Bitmap(img_connected.cols, img_connected.rows, img_connected.step1(), imgFormat, (IntPtr)img_connected.data);

		// The Bitmap is by default (objects are passed by reference) passed to a picture box by a reference.
		// The 'frame' variable goes out of scope when the function returns. Thus, the pointer is dead, and 
		// you have a GDI object with a pointer to garbage data.
		bmpConnectedComponents = gcnew Bitmap(bmpImg);

		//bmpImg = gcnew Bitmap(img_stats.cols, img_stats.rows, img_stats.step1(), imgFormat, (IntPtr)img_stats.data);

		//// The Bitmap is by default (objects are passed by reference) passed to a picture box by a reference.
		//// The 'frame' variable goes out of scope when the function returns. Thus, the pointer is dead, and 
		//// you have a GDI object with a pointer to garbage data.
		//bmpConnectedStats = gcnew Bitmap(bmpImg);

		bmpImg = gcnew Bitmap(img_contours.cols, img_contours.rows, img_contours.step1(), imgFormat, (IntPtr)img_contours.data);

		// The Bitmap is by default (objects are passed by reference) passed to a picture box by a reference.
		// The 'frame' variable goes out of scope when the function returns. Thus, the pointer is dead, and 
		// you have a GDI object with a pointer to garbage data.
		bmpBasicContours = gcnew Bitmap(bmpImg);

		panel_ConnectedComponents->BackgroundImage = bmpConnectedComponents;
		//panel_ConnectedComponentsStats->BackgroundImage = bmpConnectedStats;
		panel_BasicContours->BackgroundImage = bmpBasicContours;

		textBox_ConnectedComponents->Text = "The connected component algorithm is a very common algorithm that's used to segment " +
											"and identify parts in binary images.The connected component is an iterative algorithm " +
											"with the purpose of labeling an image using eight or four connectivity pixels.Two pixels " +
											"are connected if they have the same valueand are neighbors.In an image, each pixel has " +
											"eight neighbor pixels. ";

		textBox_BasicContours->Text =	"The findContours algorithm is one of the most used OpenCV algorithms in regards to " +
										"segment objects.This is because this algorithm was included in OpenCV from version 1.0 " +
										"and gives developers more informationand descriptors, including shapes, topological " +
										"organizations, and so on.";
	}

	// catch Opencv related exceptions
	catch (cv::Exception ex) {
		// Show the OpenCV exception in a message box
		std::string test = ex.msg;

		System::String^ verwString = marshal_as<System::String^>(test);

		MessageBox::Show("OpenCV exception: " + verwString);
	}
	// catch System related exceptions
	catch (System::Exception ^ exception) {

		// Show the Window exception in a message box
		MessageBox::Show("Windows exception: " + exception->Message);
	}

	return System::Void();
}

System::Void OpenCVCPP::Hauptfenster::CheckBox_ImgProcessingMedianBlur_Click(System::Object^ sender, System::EventArgs^ e)
{
	checkBox_ImgProcessingBlur->Checked = false;

	return System::Void();
}

System::Void OpenCVCPP::Hauptfenster::CheckBox_ImgProcessingBlur_Click(System::Object^ sender, System::EventArgs^ e)
{
	checkBox_ImgProcessingMedianBlur->Checked = false;

	return System::Void();
}

char* OpenCVCPP::Hauptfenster::convertManagedStringToANSIFormat(System::String ^ str)
{
	// Marshal.StringToHGlobalAnsi(String) Method Copies the contents of a managed String into unmanaged memory,
	// converting into ANSI format as it copies. StringToHGlobalAnsi copies the contents of a managed String 
	// object into native heap, and then converts it into American National Standards Institute (ANSI) format 
	// on the fly. This method allocates the required native heap memory

	char* convertedStr = (char*)(void*)Marshal::StringToHGlobalAnsi(str);

	return convertedStr;
}

Mat OpenCVCPP::Hauptfenster::resizeMatImageObject(Mat img, int divisor)
{
	// Mat object needs to be resized to a value which can be devided by 4
	// if (4 * Mat.cols) value cannot be devided by 4, then the Bitmap method that converts the Mat object
	// does not function. The stride value (third integer value given to the method below) must be devisible by 4
	// See: System::Drawing::Bitmap::Bitmap(int, int, int, System::Drawing::Imaging::PixelFormat, System::IntPtr)

	Mat newImg;

	if (cvImg.size().width % divisor == 0) {
		return img;
	}
	else {
		int r = cvImg.size().width + (divisor - (cvImg.size().width % divisor));
		int c = cvImg.size().height + (divisor - (cvImg.size().height % divisor));

		resize(img, newImg, cv::Size(r, c));

		return newImg;
	}
}

cv::Mat OpenCVCPP::Hauptfenster::removeChannel(Mat img, int channel, int depth)
{
	//
	if (depth == 3) {
		for (int r = 0; r < img.rows; r++)
		{
			for (int c = 0; c < img.cols; c++) {
				img.at<Vec3b>(r, c)[channel] = img.at<Vec3b>(r, c)[channel] * 0;
			}
		}
	}
	//
	else if (depth == 4) {
		for (int r = 0; r < img.rows; r++)
		{
			for (int c = 0; c < img.cols; c++) {
				img.at<Vec4b>(r, c)[channel] = img.at<Vec4b>(r, c)[channel] * 0;
			}
		}
	}

	return img;
}

cv::Mat OpenCVCPP::Hauptfenster::createDiscreetFourierTransformObject(Mat input)
{
	/* source: https://docs.opencv.org/2.4/doc/tutorials/core/discrete_fourier_transform/discrete_fourier_transform.html
	The Fourier Transform will decompose an image into its sinus and cosines components. In other words, it will transform an image from
	 its spatial domain to its frequency domain. The idea is that any function may be approximated exactly with the sum of infinite sinus and cosines functions.
	 The Fourier Transform is a way how to do this. Mathematically a two dimensional images Fourier transform is:

			F(k,l) = \displaystyle\sum\limits_{i=0}^{N-1}\sum\limits_{j=0}^{N-1} f(i,j)e^{-i2\pi(\frac{ki}{N}+\frac{lj}{N})}

			e^{ix} = \cos{x} + i\sin {x}

	Here f is the image value in its spatial domain and F in its frequency domain. The result of the transformation is complex numbers.
	Displaying this is possible either via a real image and a complex image or via a magnitude and a phase image. However, throughout the image
	processing algorithms only the magnitude image is interesting as this contains all the information we need about the images geometric structure.
	Nevertheless, if you intend to make some modifications of the image in these forms and then you need to retransform it you’ll need to preserve both of these.

	In case of digital images are discrete. This means they may take up a value from a given domain value. For example in a basic gray scale image values usually
	are between zero and 255. Therefore the Fourier Transform too needs to be of a discrete type resulting in a Discrete Fourier Transform (DFT).
	You’ll want to use this whenever you need to determine the structure of an image from a geometrical point of view. Here are the steps to follow
	(in case of a gray scale input image I):*/

	// Discreet Fourier Transform will produce a complex result with a real and a leteral (so called imaginary) component
	// We will need a Mat object with two channels that can hold both real and leteral (imaginary) components

	Mat cvImgResizedComplex[2] = { input, Mat::zeros(input.size(), CV_32F) };

	Mat cvImgPreDFT;

	merge(cvImgResizedComplex, 2, cvImgPreDFT);

	Mat cvImgDFT;

	dft(cvImgPreDFT, cvImgDFT, DFT_COMPLEX_OUTPUT);

	return cvImgDFT;
}

cv::Mat OpenCVCPP::Hauptfenster::convertDFTObjectToLogarithmicScaleAndNormalize(Mat input)
{
	Mat splitArray[2] = { Mat::zeros(input.size(), CV_32F), Mat::zeros(input.size(), CV_32F) };

	split(input, splitArray);

	Mat MagI;

	/* Transform the real and complex values to magnitude. A complex number has a real (Re) and a complex (imaginary - Im) part.
		The results of a DFT are complex numbers. The magnitude of a DFT is:

		M = \sqrt[2]{ {Re(DFT(I))} ^ 2 + {Im(DFT(I))} ^ 2 }*/

	cv::magnitude(splitArray[0], splitArray[1], MagI);

	/*	Switch to a logarithmic scale. The dynamic range of the Fourier coefficients is too large to be displayed on the screen.
		We have some small and some high changing values that we can’t observe like this. Therefore the high values will all
		turn out as white points, while the small ones as black. To use the gray scale values to for visualization we can
		transform our linear scale to a logarithmic one:

		M_1 = \log{(1 + M)}
	*/

	MagI += Scalar::all(1);                    // switch to logarithmic scale
	log(MagI, MagI);

	/*	Normalize. This is done again for visualization purposes. We now have the magnitudes, however this are still out of
		our image display range of zero to one. We normalize our values to this range using the normalize() function.
	*/

	normalize(MagI, MagI, 0, 1, NORM_MINMAX);	// Transform the matrix with float values into a
												// viewable image form (float between values 0 and 1).

	return MagI;
}

cv::Mat OpenCVCPP::Hauptfenster::recenterDiscreetFourierTransformObject(Mat input)
{
	// Recenter a discreet fourier transform output so that the low frequency information is in the center
	// and the high frequency information is in the corners instead. This is done for visualisation purposes.
	// Original data is not changed.

	// Creating four Mat objects for each quadrant
	int centerX = input.cols / 2;
	int centerY = input.rows / 2;

	Mat Q1(input, Rect(0, 0, centerX, centerY));
	Mat Q2(input, Rect(centerX, 0, centerX, centerY));
	Mat Q3(input, Rect(0, centerY, centerX, centerY));
	Mat Q4(input, Rect(centerX, centerY, centerX, centerY));

	// Temporary Mat object for swaping different corners
	Mat swap;

	// Copying Q1 to temporary swap object, so that we can swap two corners
	Q1.copyTo(swap);
	Q4.copyTo(Q1);
	// Now copy what is in swap to Q4
	swap.copyTo(Q4);

	// Copying Q2 to temporary swap object, so that we can swap two corners
	Q2.copyTo(swap);
	Q3.copyTo(Q2);
	// Now copy what is in swap to Q4
	swap.copyTo(Q3);

	return input;
}

cv::Mat OpenCVCPP::Hauptfenster::invertDiscreetFourierTransformObject(Mat input)
{
	Mat inverse;

	dft(input, inverse, DFT_INVERSE | DFT_REAL_OUTPUT | DFT_SCALE);

	return inverse;
}

string OpenCVCPP::Hauptfenster::matType2str(int type)
{
	/*
	+--------+----+----+----+----+------+------+------+------+
	|        | C1 | C2 | C3 | C4 | C(5) | C(6) | C(7) | C(8) |
	+--------+----+----+----+----+------+------+------+------+
	| CV_8U  |  0 |  8 | 16 | 24 |   32 |   40 |   48 |   56 |
	| CV_8S  |  1 |  9 | 17 | 25 |   33 |   41 |   49 |   57 |
	| CV_16U |  2 | 10 | 18 | 26 |   34 |   42 |   50 |   58 |
	| CV_16S |  3 | 11 | 19 | 27 |   35 |   43 |   51 |   59 |
	| CV_32S |  4 | 12 | 20 | 28 |   36 |   44 |   52 |   60 |
	| CV_32F |  5 | 13 | 21 | 29 |   37 |   45 |   53 |   61 |
	| CV_64F |  6 | 14 | 22 | 30 |   38 |   46 |   54 |   62 |
	+--------+----+----+----+----+------+------+------+------+
	*/


	return string();
}

/**
* Calcualte image pattern from an input image
* @param img Mat input image to calculate the light pattern
* @return a Mat pattern image
*/
cv::Mat OpenCVCPP::Hauptfenster::calculateLightPattern(Mat img)
{
	Mat pattern;
	// Basic and effective way to calculate the light pattern from one image
	blur(img, pattern, cv::Size(img.cols / 3, img.cols / 3));
	return pattern;
}

Mat OpenCVCPP::Hauptfenster::removeLight(Mat img, Mat pattern, int method)
/**
* Remove th light and return new image without light
* @param img Mat image to remove the light pattern
* @param pattern Mat image with light pattern
* @return a new image Mat without light
*/
{
	Mat aux;
	// if method is normalization
	if (method == 1)
	{
		// Require change our image to 32 float for division
		Mat img32, pattern32;
		img.convertTo(img32, CV_32F);
		pattern.convertTo(pattern32, CV_32F);
		// Divide the imabe by the pattern
		aux = 1 - (img32 / pattern32);
		// Convert 8 bits format
		aux.convertTo(aux, CV_8U, 255);
	}
	else {
		aux = pattern - img;
	}
	//equalizeHist( aux, aux );
	return aux;
}

/*	The connected component algorithm is a very common algorithm that's used to segment
	and identify parts in binary images.The connected component is an iterative algorithm
	with the purpose of labeling an image using eight or four connectivity pixels.Two pixels
	are connected if they have the same valueand are neighbors.In an image, each pixel has
	eight neighbor pixels. */
cv::Mat OpenCVCPP::Hauptfenster::ConnectedComponents(Mat img)
{
	// Use connected components to divide our possibles parts of images 
	Mat labels;
	auto num_objects = connectedComponents(img, labels);
	// Check the number of objects detected
	if (num_objects < 2) {
		Console::WriteLine("No objects detected");
		return Mat();
	}
	else {
		Console::WriteLine("Number of objects detected: " + (num_objects - 1));
	}
	// Create output image coloring the objects
	Mat output = Mat::zeros(img.rows, img.cols, CV_8UC3);
	RNG rng(0xFFFFFFFF);
	for (auto i = 1; i < num_objects; i++) {
		Mat mask = labels == i;
		output.setTo(randomColor(rng), mask);
	}
	
	//imshow("Result", output);
	
	return output;
}

cv::Mat OpenCVCPP::Hauptfenster::ConnectedComponentsStats(Mat img)
{
	// Use connected components with stats
	Mat labels, stats, centroids;
	auto num_objects = connectedComponentsWithStats(img, labels, stats, centroids);
	// Check the number of objects detected
	if (num_objects < 2) {
		Console::WriteLine("No objects detected");
		return Mat();
	}
	else {
		Console::WriteLine("Number of objects detected: " + (num_objects - 1));
	}
	// Create output image coloring the objects and show area
	Mat output = Mat::zeros(img.rows, img.cols, CV_8UC3);
	RNG rng(0xFFFFFFFF);
	for (auto i = 1; i < num_objects; i++) {
		
		//Console::WriteLine("Object " + i + " with pos: ");
		//Console::WriteLine(centroids.at<Point2d>(i)); +" with area " + stats.at<int>(i, CC_STAT_AREA));
		
		Mat mask = labels == i;
		output.setTo(randomColor(rng), mask);
		// draw text with area
		stringstream ss;
		ss << "area: " << stats.at<int>(i, CC_STAT_AREA);

		putText(output,
			ss.str(),
			centroids.at<Point2d>(i),
			FONT_HERSHEY_SIMPLEX,
			0.4,
			Scalar(255, 255, 255));
	}
	
	//imshow("Result", output);
	
	return output;
}

/*	The findContours algorithm is one of the most used OpenCV algorithms in regards to
	segment objects.This is because this algorithm was included in OpenCV from version 1.0
	and gives developers more information and descriptors, including shapes, topological
	organizations, and so on.
*/
cv::Mat OpenCVCPP::Hauptfenster::FindContoursBasic(Mat img)
{
	vector<vector<cv::Point> > contours;
	findContours(img, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	Mat output = Mat::zeros(img.rows, img.cols, CV_8UC3);
	// Check the number of objects detected
	if (contours.size() == 0) {
		Console::WriteLine("No objects detected");
		return Mat();
	}
	else {
		Console::WriteLine("Number of objects detected: " + contours.size());
	}
	RNG rng(0xFFFFFFFF);
	for (auto i = 0; i < contours.size(); i++)
		drawContours(output, contours, i, randomColor(rng));
	
	//imshow("Result", output);
	return output;
}

Scalar OpenCVCPP::Hauptfenster::randomColor(RNG& rng)
{
	auto icolor = (unsigned)rng;
	return Scalar(icolor & 255, (icolor >> 8) & 255, (icolor >> 16) & 255);
}

System::Void OpenCVCPP::Hauptfenster::enableDisableButtons(System::String^ str)
{
	if (str == "enable") {
		button_LoadImage->Enabled = true;
		// ---------------------------------------
		button_SplitChannels->Enabled = true;
		button_RemoveBGR->Enabled = true;
		// ---------------------------------------
		button_GrayFilter->Enabled = true;
		button_BlurFilter->Enabled = true;
		button_Sobel->Enabled = true;
		// ---------------------------------------
		button_VisualizeDFT->Enabled = true;
		button_InvertDFT->Enabled = true;
		button_RecenterDFT->Enabled = true;
		// ---------------------------------------
		button_CreateHistogram->Enabled = true;
		// ---------------------------------------
		button_EqualizeImageColor->Enabled = true;
		button_LomographyEffect->Enabled = true;
		button_CartoonizeEffect->Enabled = true;
		// ---------------------------------------
		button_LoadLightPatternImage->Enabled = true;
		button_NoiseRemoval->Enabled = true;
		button_RemoveLightAndThreshold->Enabled = true;
		button_ProcessLightPattern->Enabled = true;
		// ---------------------------------------
		button_RunSegmentationAlgorithms->Enabled = true;
	}
	else if (str == "disable") {
		button_LoadImage->Enabled = false;
		// ---------------------------------------
		button_SplitChannels->Enabled = false;
		button_RemoveBGR->Enabled = false;
		// ---------------------------------------
		button_GrayFilter->Enabled = false;
		button_BlurFilter->Enabled = false;
		button_Sobel->Enabled = false;
		// ---------------------------------------
		button_VisualizeDFT->Enabled = false;
		button_InvertDFT->Enabled = false;
		button_RecenterDFT->Enabled = false;
		// ---------------------------------------
		button_CreateHistogram->Enabled = false;
		// ---------------------------------------
		button_EqualizeImageColor->Enabled = false;
		button_LomographyEffect->Enabled = false;
		button_CartoonizeEffect->Enabled = false;
		// ---------------------------------------
		button_LoadLightPatternImage->Enabled = false;
		button_NoiseRemoval->Enabled = false;
		button_RemoveLightAndThreshold->Enabled = false;
		button_ProcessLightPattern->Enabled = false;
		// ---------------------------------------
		button_RunSegmentationAlgorithms->Enabled = false;
	}

	return System::Void();
}
