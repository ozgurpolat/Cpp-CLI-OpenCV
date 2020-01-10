			//------------------ Solution 1: Working code reads gray image and shows on the screen -----------------------------------------

			//cvImg = imread(convertedFileName, cv::IMREAD_GRAYSCALE);

			//Mat color;

			//cvtColor(cvImg, color, cv::COLOR_GRAY2RGB, 3);

			//Bitmap^ bmpImg = gcnew Bitmap(color.cols, color.rows, color.step1(), Imaging::PixelFormat::Format24bppRgb, (IntPtr)color.data);

			//panel_MainImage->BackgroundImage = bmpImg;
			//panel_MainImage->Refresh();

			//--------------------- Solution 2: Working code reads color image converts it to gray and than back to color -------------------

			//cvImg = imread(convertedFileName, cv::IMREAD_UNCHANGED);

			//Console::WriteLine(cvImg.depth().GetTypeCode());
			//Console::WriteLine(cvImg.channels());

			//// Resizing the image so that cvImgResized.cols is divisible by 4
			//Mat cvImgResized = resizeMatImageObject(cvImg, 4); 

			//Mat gray0;
			//Mat gray;
			//Mat color;

			//cvtColor(cvImgResized, gray0, cv::COLOR_BGR2GRAY);
			//cvtColor(gray0, color, cv::COLOR_GRAY2RGB, 3); //  Converting it back to color

			//Imaging::PixelFormat test;

			//test = Imaging::PixelFormat::Format24bppRgb;

			//Bitmap^ bmpImg = gcnew Bitmap(color.cols, color.rows, 3 * color.rows, test, (IntPtr)color.data);

			//panel_MainImage->BackgroundImage = bmpImg;
			//panel_MainImage->Refresh();

			//------------------- Solution 3: Load the image in grayscale, resizes it and converts it to color then loads it on to the screen --------

			//cvImg = imread(convertedFileName, cv::IMREAD_GRAYSCALE);

			//Console::WriteLine(cvImg.depth().GetTypeCode());
			//Console::WriteLine(cvImg.channels());

			//Mat cvImgNew = resizeMatImageObject(cvImg, 4);

			//Console::WriteLine(cvImgNew.depth().GetTypeCode());
			//Console::WriteLine(cvImgNew.channels());

			//Mat color;

			//cvtColor(cvImgNew, color, cv::COLOR_GRAY2RGB, 3);

			//Bitmap^ bmpImg = gcnew Bitmap(color.cols, color.rows, 3 * color.cols, Imaging::PixelFormat::Format24bppRgb, (IntPtr)color.data);

			//----------------------------------------------------------------------------------------------------------