#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <msclr/marshal_cppstd.h> // Bibliothek zur Umwandlung von verwaltet in unverwaltet
#include <stdint.h> // Defines types such as signed int unsigned int, long etc. Allows us for example to type "uint8_t" instead of unsigned char

namespace OpenCVCPP {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	using namespace std;
	using namespace cv;
	using namespace msclr::interop;

	/// <summary>
	/// Zusammenfassung für Hauptfenster
	/// </summary>
	public ref class Hauptfenster : public System::Windows::Forms::Form
	{
	private:
		System::String^ imgFileName;
		System::String^ imgLightPatternFileName;
		Bitmap^ bmpMain;
		Bitmap^ bmpBlueChannel;
		Bitmap^ bmpGreenChannel;
		Bitmap^ bmpRedChannel;
		Bitmap^ bmpGrayscale;
		Bitmap^ bmpBlur;
		Bitmap^ bmpSobel;
		Bitmap^ bmpVisualizeDFT;
		Bitmap^ bmpRecenterDFT;
		Bitmap^ bmpInvertDFT;
		Bitmap^ bmpShowHistogram;
		Bitmap^ bmpLomography;
		Bitmap^ bmpCartoonize;
		Bitmap^ bmpNoiseRemoval;
		Bitmap^ bmpLightPattern;
		Bitmap^ bmpLightPattern_1;
		Bitmap^ bmpLightPattern_2;
		Bitmap^ bmpLightPattern_3;
		Bitmap^ bmpLightPattern_4;
		Bitmap^ bmpLightPattern_5;
		Bitmap^ bmpThreshold;
		Bitmap^ bmpConnectedComponents;
		Bitmap^ bmpConnectedStats;
		Bitmap^ bmpBasicContours;

	private: System::Windows::Forms::Button^ button_Sobel;
	private: System::Windows::Forms::TabPage^ tabPage3;
	private: System::Windows::Forms::TextBox^ textBox_InvertDFT;

	private: System::Windows::Forms::TextBox^ textBox_RecenterDFT;

	private: System::Windows::Forms::TextBox^ textBox_VisualizeDFT;

	private: System::Windows::Forms::Button^ button_VisualizeDFT;
	private: System::Windows::Forms::TabPage^ tabPage4;
	private: System::Windows::Forms::Button^ button_RecenterDFT;
	private: System::Windows::Forms::Button^ button_CreateHistogram;
	private: System::Windows::Forms::Panel^ panel_CreateHistogram;

	private: System::Windows::Forms::TabPage^ tabPage5;
	private: System::Windows::Forms::Button^ button_CartoonizeEffect;
	private: System::Windows::Forms::Button^ button_LomographyEffect;
	private: System::Windows::Forms::TextBox^ textBox11;
	private: System::Windows::Forms::TextBox^ textBox12;
	private: System::Windows::Forms::TextBox^ textBox13;
	private: System::Windows::Forms::Button^ button_EqualizeImageColor;
	private: System::Windows::Forms::Panel^ panel_BlueChannel;
	private: System::Windows::Forms::Panel^ panel_RedChannel;
	private: System::Windows::Forms::Panel^ panel_GreenChannel;
	private: System::Windows::Forms::Panel^ panel_Grayscale;
	private: System::Windows::Forms::Panel^ panel_Sobel;
	private: System::Windows::Forms::Panel^ panel_Blur;
	private: System::Windows::Forms::Panel^ panel_InvertDFT;
	private: System::Windows::Forms::Panel^ panel_RecenterDFT;
	private: System::Windows::Forms::Panel^ panel_VisualizeDFT;
	private: System::Windows::Forms::TextBox^ textBox_CreateHistogram;

	private: System::Windows::Forms::Panel^ panel_CartoonizeEffect;
	private: System::Windows::Forms::Panel^ panel_LomographyFilter;
	private: System::Windows::Forms::Panel^ panel_EqualizeImageColor;
	private: System::Windows::Forms::Panel^ panel_MainImage;
	private: System::Windows::Forms::TabPage^ tabPage6;
	private: System::Windows::Forms::Panel^ panel_RemoveLightAndThreshold;
	private: System::Windows::Forms::CheckBox^ checkBox_Method_Normalize_i;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Panel^ panel_ProcessLightPattern_2;
	private: System::Windows::Forms::Panel^ panel_ProcessLightPattern_1;
	private: System::Windows::Forms::CheckBox^ checkBox_Method_Normalize_ii;
	private: System::Windows::Forms::Panel^ panel_ProcessLightPattern_5;
	private: System::Windows::Forms::Panel^ panel_ProcessLightPattern_4;
	private: System::Windows::Forms::Panel^ panel_ProcessLightPattern_3;
	private: System::Windows::Forms::Button^ button_RemoveLightAndThreshold;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button_ProcessLightPattern;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button_LoadLightPatternImage;
	private: System::Windows::Forms::Panel^ panel_LoadLightPattern;
	private: System::Windows::Forms::Label^ label_NoiseRemoval;
	private: System::Windows::Forms::Panel^ panel_NoiseRemoval;
	private: System::Windows::Forms::TrackBar^ trackBar_NoiseRemovalIndex;
	private: System::Windows::Forms::CheckBox^ checkBox_ImgProcessingBlur;
	private: System::Windows::Forms::CheckBox^ checkBox_ImgProcessingMedianBlur;
	private: System::Windows::Forms::TextBox^ textBox_NoiseRemoval;
	private: System::Windows::Forms::Button^ button_NoiseRemoval;
	private: System::Windows::Forms::TabPage^ tabPage7;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Panel^ panel_ConnectedComponents;
	private: System::Windows::Forms::TextBox^ textBox_ConnectedComponents;
	private: System::Windows::Forms::Button^ button_RunSegmentationAlgorithms;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Panel^ panel_BasicContours;
	private: System::Windows::Forms::TextBox^ textBox_BasicContours;
	private: System::Windows::Forms::CheckBox^ checkBox_Method_Normalize_iii;
	private: System::Windows::Forms::TextBox^ textBox_RemoveLightAndThreshold;
	private: System::Windows::Forms::TextBox^ textBox_LoadLightPattern;
	private: System::Windows::Forms::Button^ button_InvertDFT;

	public:
		Hauptfenster(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Hauptfenster()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button_LoadImage;
	private: System::Windows::Forms::Button^ button_SplitChannels;
	protected:
	protected:
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;
private: System::Windows::Forms::TextBox^ textBox_RedChannel;
private: System::Windows::Forms::TextBox^ textBox_GreenChannel;




private: System::Windows::Forms::TextBox^ textBox_BlueChannel;
private: System::Windows::Forms::TextBox^ textBox_Sobel;


private: System::Windows::Forms::TextBox^ textBox_Blur;

private: System::Windows::Forms::TextBox^ textBox_Grayscale;

	private: System::Windows::Forms::Button^ button_GrayFilter;
private: System::Windows::Forms::TextBox^ textBox_MainImage;

	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::Label^ label_Blur;
	private: System::Windows::Forms::Button^ button_BlurFilter;
	private: System::Windows::Forms::TrackBar^ trackBar_BlurIndex;
	private: System::Windows::Forms::Button^ button_RemoveBGR;
	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button_LoadImage = (gcnew System::Windows::Forms::Button());
			this->button_SplitChannels = (gcnew System::Windows::Forms::Button());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->panel_RedChannel = (gcnew System::Windows::Forms::Panel());
			this->panel_GreenChannel = (gcnew System::Windows::Forms::Panel());
			this->panel_BlueChannel = (gcnew System::Windows::Forms::Panel());
			this->button_RemoveBGR = (gcnew System::Windows::Forms::Button());
			this->textBox_RedChannel = (gcnew System::Windows::Forms::TextBox());
			this->textBox_GreenChannel = (gcnew System::Windows::Forms::TextBox());
			this->textBox_BlueChannel = (gcnew System::Windows::Forms::TextBox());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->panel_Sobel = (gcnew System::Windows::Forms::Panel());
			this->panel_Blur = (gcnew System::Windows::Forms::Panel());
			this->panel_Grayscale = (gcnew System::Windows::Forms::Panel());
			this->button_Sobel = (gcnew System::Windows::Forms::Button());
			this->label_Blur = (gcnew System::Windows::Forms::Label());
			this->trackBar_BlurIndex = (gcnew System::Windows::Forms::TrackBar());
			this->button_BlurFilter = (gcnew System::Windows::Forms::Button());
			this->textBox_Sobel = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Blur = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Grayscale = (gcnew System::Windows::Forms::TextBox());
			this->button_GrayFilter = (gcnew System::Windows::Forms::Button());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->panel_InvertDFT = (gcnew System::Windows::Forms::Panel());
			this->panel_RecenterDFT = (gcnew System::Windows::Forms::Panel());
			this->panel_VisualizeDFT = (gcnew System::Windows::Forms::Panel());
			this->button_InvertDFT = (gcnew System::Windows::Forms::Button());
			this->button_RecenterDFT = (gcnew System::Windows::Forms::Button());
			this->textBox_InvertDFT = (gcnew System::Windows::Forms::TextBox());
			this->textBox_RecenterDFT = (gcnew System::Windows::Forms::TextBox());
			this->textBox_VisualizeDFT = (gcnew System::Windows::Forms::TextBox());
			this->button_VisualizeDFT = (gcnew System::Windows::Forms::Button());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->textBox_CreateHistogram = (gcnew System::Windows::Forms::TextBox());
			this->button_CreateHistogram = (gcnew System::Windows::Forms::Button());
			this->panel_CreateHistogram = (gcnew System::Windows::Forms::Panel());
			this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
			this->panel_CartoonizeEffect = (gcnew System::Windows::Forms::Panel());
			this->panel_LomographyFilter = (gcnew System::Windows::Forms::Panel());
			this->panel_EqualizeImageColor = (gcnew System::Windows::Forms::Panel());
			this->button_CartoonizeEffect = (gcnew System::Windows::Forms::Button());
			this->button_LomographyEffect = (gcnew System::Windows::Forms::Button());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			this->button_EqualizeImageColor = (gcnew System::Windows::Forms::Button());
			this->tabPage6 = (gcnew System::Windows::Forms::TabPage());
			this->textBox_RemoveLightAndThreshold = (gcnew System::Windows::Forms::TextBox());
			this->textBox_LoadLightPattern = (gcnew System::Windows::Forms::TextBox());
			this->panel_RemoveLightAndThreshold = (gcnew System::Windows::Forms::Panel());
			this->checkBox_Method_Normalize_i = (gcnew System::Windows::Forms::CheckBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel_ProcessLightPattern_2 = (gcnew System::Windows::Forms::Panel());
			this->panel_ProcessLightPattern_1 = (gcnew System::Windows::Forms::Panel());
			this->checkBox_Method_Normalize_ii = (gcnew System::Windows::Forms::CheckBox());
			this->panel_ProcessLightPattern_5 = (gcnew System::Windows::Forms::Panel());
			this->panel_ProcessLightPattern_4 = (gcnew System::Windows::Forms::Panel());
			this->panel_ProcessLightPattern_3 = (gcnew System::Windows::Forms::Panel());
			this->button_RemoveLightAndThreshold = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button_ProcessLightPattern = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button_LoadLightPatternImage = (gcnew System::Windows::Forms::Button());
			this->panel_LoadLightPattern = (gcnew System::Windows::Forms::Panel());
			this->label_NoiseRemoval = (gcnew System::Windows::Forms::Label());
			this->panel_NoiseRemoval = (gcnew System::Windows::Forms::Panel());
			this->trackBar_NoiseRemovalIndex = (gcnew System::Windows::Forms::TrackBar());
			this->checkBox_ImgProcessingBlur = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_ImgProcessingMedianBlur = (gcnew System::Windows::Forms::CheckBox());
			this->textBox_NoiseRemoval = (gcnew System::Windows::Forms::TextBox());
			this->button_NoiseRemoval = (gcnew System::Windows::Forms::Button());
			this->tabPage7 = (gcnew System::Windows::Forms::TabPage());
			this->checkBox_Method_Normalize_iii = (gcnew System::Windows::Forms::CheckBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->panel_BasicContours = (gcnew System::Windows::Forms::Panel());
			this->textBox_BasicContours = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->panel_ConnectedComponents = (gcnew System::Windows::Forms::Panel());
			this->textBox_ConnectedComponents = (gcnew System::Windows::Forms::TextBox());
			this->button_RunSegmentationAlgorithms = (gcnew System::Windows::Forms::Button());
			this->textBox_MainImage = (gcnew System::Windows::Forms::TextBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->panel_MainImage = (gcnew System::Windows::Forms::Panel());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_BlurIndex))->BeginInit();
			this->tabPage3->SuspendLayout();
			this->tabPage4->SuspendLayout();
			this->tabPage5->SuspendLayout();
			this->tabPage6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_NoiseRemovalIndex))->BeginInit();
			this->tabPage7->SuspendLayout();
			this->SuspendLayout();
			// 
			// button_LoadImage
			// 
			this->button_LoadImage->Font = (gcnew System::Drawing::Font(L"Verdana", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_LoadImage->Location = System::Drawing::Point(12, 53);
			this->button_LoadImage->Name = L"button_LoadImage";
			this->button_LoadImage->Size = System::Drawing::Size(116, 39);
			this->button_LoadImage->TabIndex = 0;
			this->button_LoadImage->Text = L"Load Image";
			this->button_LoadImage->UseVisualStyleBackColor = true;
			this->button_LoadImage->Click += gcnew System::EventHandler(this, &Hauptfenster::Button_LoadImage_Click);
			// 
			// button_SplitChannels
			// 
			this->button_SplitChannels->Enabled = false;
			this->button_SplitChannels->Location = System::Drawing::Point(23, 21);
			this->button_SplitChannels->Name = L"button_SplitChannels";
			this->button_SplitChannels->Size = System::Drawing::Size(129, 39);
			this->button_SplitChannels->TabIndex = 1;
			this->button_SplitChannels->Text = L"Split Channels";
			this->button_SplitChannels->UseVisualStyleBackColor = true;
			this->button_SplitChannels->Click += gcnew System::EventHandler(this, &Hauptfenster::Button_SplitChannels_Click);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabPage4);
			this->tabControl1->Controls->Add(this->tabPage5);
			this->tabControl1->Controls->Add(this->tabPage6);
			this->tabControl1->Controls->Add(this->tabPage7);
			this->tabControl1->Font = (gcnew System::Drawing::Font(L"Verdana", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tabControl1->Location = System::Drawing::Point(334, 5);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(999, 669);
			this->tabControl1->TabIndex = 3;
			// 
			// tabPage1
			// 
			this->tabPage1->BackColor = System::Drawing::SystemColors::Control;
			this->tabPage1->Controls->Add(this->panel_RedChannel);
			this->tabPage1->Controls->Add(this->panel_GreenChannel);
			this->tabPage1->Controls->Add(this->panel_BlueChannel);
			this->tabPage1->Controls->Add(this->button_RemoveBGR);
			this->tabPage1->Controls->Add(this->textBox_RedChannel);
			this->tabPage1->Controls->Add(this->textBox_GreenChannel);
			this->tabPage1->Controls->Add(this->textBox_BlueChannel);
			this->tabPage1->Controls->Add(this->button_SplitChannels);
			this->tabPage1->Location = System::Drawing::Point(4, 27);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(991, 638);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Channel Effects";
			// 
			// panel_RedChannel
			// 
			this->panel_RedChannel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->panel_RedChannel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_RedChannel->Location = System::Drawing::Point(661, 77);
			this->panel_RedChannel->Name = L"panel_RedChannel";
			this->panel_RedChannel->Size = System::Drawing::Size(300, 300);
			this->panel_RedChannel->TabIndex = 10;
			// 
			// panel_GreenChannel
			// 
			this->panel_GreenChannel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->panel_GreenChannel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_GreenChannel->Location = System::Drawing::Point(342, 77);
			this->panel_GreenChannel->Name = L"panel_GreenChannel";
			this->panel_GreenChannel->Size = System::Drawing::Size(300, 300);
			this->panel_GreenChannel->TabIndex = 9;
			// 
			// panel_BlueChannel
			// 
			this->panel_BlueChannel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->panel_BlueChannel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_BlueChannel->Location = System::Drawing::Point(25, 77);
			this->panel_BlueChannel->Name = L"panel_BlueChannel";
			this->panel_BlueChannel->Size = System::Drawing::Size(300, 300);
			this->panel_BlueChannel->TabIndex = 8;
			// 
			// button_RemoveBGR
			// 
			this->button_RemoveBGR->Enabled = false;
			this->button_RemoveBGR->Location = System::Drawing::Point(158, 21);
			this->button_RemoveBGR->Name = L"button_RemoveBGR";
			this->button_RemoveBGR->Size = System::Drawing::Size(165, 39);
			this->button_RemoveBGR->TabIndex = 7;
			this->button_RemoveBGR->Text = L"Remove B/G/R";
			this->button_RemoveBGR->UseVisualStyleBackColor = true;
			this->button_RemoveBGR->Click += gcnew System::EventHandler(this, &Hauptfenster::Button_RemoveBGR_Click);
			// 
			// textBox_RedChannel
			// 
			this->textBox_RedChannel->BackColor = System::Drawing::SystemColors::Control;
			this->textBox_RedChannel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox_RedChannel->Location = System::Drawing::Point(661, 392);
			this->textBox_RedChannel->Multiline = true;
			this->textBox_RedChannel->Name = L"textBox_RedChannel";
			this->textBox_RedChannel->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox_RedChannel->Size = System::Drawing::Size(300, 150);
			this->textBox_RedChannel->TabIndex = 6;
			// 
			// textBox_GreenChannel
			// 
			this->textBox_GreenChannel->BackColor = System::Drawing::SystemColors::Control;
			this->textBox_GreenChannel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox_GreenChannel->Location = System::Drawing::Point(342, 392);
			this->textBox_GreenChannel->Multiline = true;
			this->textBox_GreenChannel->Name = L"textBox_GreenChannel";
			this->textBox_GreenChannel->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox_GreenChannel->Size = System::Drawing::Size(300, 150);
			this->textBox_GreenChannel->TabIndex = 5;
			// 
			// textBox_BlueChannel
			// 
			this->textBox_BlueChannel->BackColor = System::Drawing::SystemColors::Control;
			this->textBox_BlueChannel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox_BlueChannel->Location = System::Drawing::Point(23, 392);
			this->textBox_BlueChannel->Multiline = true;
			this->textBox_BlueChannel->Name = L"textBox_BlueChannel";
			this->textBox_BlueChannel->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox_BlueChannel->Size = System::Drawing::Size(300, 150);
			this->textBox_BlueChannel->TabIndex = 4;
			// 
			// tabPage2
			// 
			this->tabPage2->BackColor = System::Drawing::SystemColors::Control;
			this->tabPage2->Controls->Add(this->panel_Sobel);
			this->tabPage2->Controls->Add(this->panel_Blur);
			this->tabPage2->Controls->Add(this->panel_Grayscale);
			this->tabPage2->Controls->Add(this->button_Sobel);
			this->tabPage2->Controls->Add(this->label_Blur);
			this->tabPage2->Controls->Add(this->trackBar_BlurIndex);
			this->tabPage2->Controls->Add(this->button_BlurFilter);
			this->tabPage2->Controls->Add(this->textBox_Sobel);
			this->tabPage2->Controls->Add(this->textBox_Blur);
			this->tabPage2->Controls->Add(this->textBox_Grayscale);
			this->tabPage2->Controls->Add(this->button_GrayFilter);
			this->tabPage2->Location = System::Drawing::Point(4, 27);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(991, 638);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Apply Image Effects";
			// 
			// panel_Sobel
			// 
			this->panel_Sobel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->panel_Sobel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_Sobel->Location = System::Drawing::Point(670, 71);
			this->panel_Sobel->Name = L"panel_Sobel";
			this->panel_Sobel->Size = System::Drawing::Size(300, 300);
			this->panel_Sobel->TabIndex = 18;
			// 
			// panel_Blur
			// 
			this->panel_Blur->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->panel_Blur->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_Blur->Location = System::Drawing::Point(345, 72);
			this->panel_Blur->Name = L"panel_Blur";
			this->panel_Blur->Size = System::Drawing::Size(300, 300);
			this->panel_Blur->TabIndex = 17;
			// 
			// panel_Grayscale
			// 
			this->panel_Grayscale->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->panel_Grayscale->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_Grayscale->Location = System::Drawing::Point(21, 72);
			this->panel_Grayscale->Name = L"panel_Grayscale";
			this->panel_Grayscale->Size = System::Drawing::Size(300, 300);
			this->panel_Grayscale->TabIndex = 16;
			// 
			// button_Sobel
			// 
			this->button_Sobel->Enabled = false;
			this->button_Sobel->Location = System::Drawing::Point(670, 21);
			this->button_Sobel->Name = L"button_Sobel";
			this->button_Sobel->Size = System::Drawing::Size(115, 35);
			this->button_Sobel->TabIndex = 15;
			this->button_Sobel->Text = L"sobel effect";
			this->button_Sobel->UseVisualStyleBackColor = true;
			this->button_Sobel->Click += gcnew System::EventHandler(this, &Hauptfenster::Button_Sobel_Click);
			// 
			// label_Blur
			// 
			this->label_Blur->AutoSize = true;
			this->label_Blur->Location = System::Drawing::Point(612, 29);
			this->label_Blur->Name = L"label_Blur";
			this->label_Blur->Size = System::Drawing::Size(18, 18);
			this->label_Blur->TabIndex = 13;
			this->label_Blur->Text = L"1";
			// 
			// trackBar_BlurIndex
			// 
			this->trackBar_BlurIndex->LargeChange = 10;
			this->trackBar_BlurIndex->Location = System::Drawing::Point(466, 21);
			this->trackBar_BlurIndex->Maximum = 100;
			this->trackBar_BlurIndex->Minimum = 1;
			this->trackBar_BlurIndex->Name = L"trackBar_BlurIndex";
			this->trackBar_BlurIndex->Size = System::Drawing::Size(140, 45);
			this->trackBar_BlurIndex->TabIndex = 10;
			this->trackBar_BlurIndex->TickFrequency = 10;
			this->trackBar_BlurIndex->Value = 1;
			this->trackBar_BlurIndex->Scroll += gcnew System::EventHandler(this, &Hauptfenster::trackBar_BlurIndex_Scroll);
			// 
			// button_BlurFilter
			// 
			this->button_BlurFilter->Enabled = false;
			this->button_BlurFilter->Location = System::Drawing::Point(345, 21);
			this->button_BlurFilter->Name = L"button_BlurFilter";
			this->button_BlurFilter->Size = System::Drawing::Size(115, 35);
			this->button_BlurFilter->TabIndex = 14;
			this->button_BlurFilter->Text = L"blur filter";
			this->button_BlurFilter->UseVisualStyleBackColor = true;
			this->button_BlurFilter->Click += gcnew System::EventHandler(this, &Hauptfenster::Button_BlurFilter_Click);
			// 
			// textBox_Sobel
			// 
			this->textBox_Sobel->BackColor = System::Drawing::SystemColors::Control;
			this->textBox_Sobel->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox_Sobel->Location = System::Drawing::Point(670, 392);
			this->textBox_Sobel->Multiline = true;
			this->textBox_Sobel->Name = L"textBox_Sobel";
			this->textBox_Sobel->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox_Sobel->Size = System::Drawing::Size(300, 150);
			this->textBox_Sobel->TabIndex = 13;
			// 
			// textBox_Blur
			// 
			this->textBox_Blur->BackColor = System::Drawing::SystemColors::Control;
			this->textBox_Blur->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox_Blur->Location = System::Drawing::Point(345, 392);
			this->textBox_Blur->Multiline = true;
			this->textBox_Blur->Name = L"textBox_Blur";
			this->textBox_Blur->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox_Blur->Size = System::Drawing::Size(300, 150);
			this->textBox_Blur->TabIndex = 12;
			// 
			// textBox_Grayscale
			// 
			this->textBox_Grayscale->BackColor = System::Drawing::SystemColors::Control;
			this->textBox_Grayscale->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox_Grayscale->Location = System::Drawing::Point(21, 392);
			this->textBox_Grayscale->Multiline = true;
			this->textBox_Grayscale->Name = L"textBox_Grayscale";
			this->textBox_Grayscale->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox_Grayscale->Size = System::Drawing::Size(300, 150);
			this->textBox_Grayscale->TabIndex = 11;
			// 
			// button_GrayFilter
			// 
			this->button_GrayFilter->Enabled = false;
			this->button_GrayFilter->Location = System::Drawing::Point(21, 21);
			this->button_GrayFilter->Name = L"button_GrayFilter";
			this->button_GrayFilter->Size = System::Drawing::Size(118, 35);
			this->button_GrayFilter->TabIndex = 8;
			this->button_GrayFilter->Text = L"gray filter";
			this->button_GrayFilter->UseVisualStyleBackColor = true;
			this->button_GrayFilter->Click += gcnew System::EventHandler(this, &Hauptfenster::Button_GrayFilter_Click);
			// 
			// tabPage3
			// 
			this->tabPage3->BackColor = System::Drawing::SystemColors::Control;
			this->tabPage3->Controls->Add(this->panel_InvertDFT);
			this->tabPage3->Controls->Add(this->panel_RecenterDFT);
			this->tabPage3->Controls->Add(this->panel_VisualizeDFT);
			this->tabPage3->Controls->Add(this->button_InvertDFT);
			this->tabPage3->Controls->Add(this->button_RecenterDFT);
			this->tabPage3->Controls->Add(this->textBox_InvertDFT);
			this->tabPage3->Controls->Add(this->textBox_RecenterDFT);
			this->tabPage3->Controls->Add(this->textBox_VisualizeDFT);
			this->tabPage3->Controls->Add(this->button_VisualizeDFT);
			this->tabPage3->Location = System::Drawing::Point(4, 27);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(991, 638);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Discrete Fourier Transform";
			// 
			// panel_InvertDFT
			// 
			this->panel_InvertDFT->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->panel_InvertDFT->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_InvertDFT->Location = System::Drawing::Point(670, 75);
			this->panel_InvertDFT->Name = L"panel_InvertDFT";
			this->panel_InvertDFT->Size = System::Drawing::Size(300, 300);
			this->panel_InvertDFT->TabIndex = 25;
			// 
			// panel_RecenterDFT
			// 
			this->panel_RecenterDFT->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->panel_RecenterDFT->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_RecenterDFT->Location = System::Drawing::Point(345, 75);
			this->panel_RecenterDFT->Name = L"panel_RecenterDFT";
			this->panel_RecenterDFT->Size = System::Drawing::Size(300, 300);
			this->panel_RecenterDFT->TabIndex = 24;
			// 
			// panel_VisualizeDFT
			// 
			this->panel_VisualizeDFT->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->panel_VisualizeDFT->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_VisualizeDFT->Location = System::Drawing::Point(25, 75);
			this->panel_VisualizeDFT->Name = L"panel_VisualizeDFT";
			this->panel_VisualizeDFT->Size = System::Drawing::Size(300, 300);
			this->panel_VisualizeDFT->TabIndex = 23;
			// 
			// button_InvertDFT
			// 
			this->button_InvertDFT->Enabled = false;
			this->button_InvertDFT->Location = System::Drawing::Point(670, 25);
			this->button_InvertDFT->Name = L"button_InvertDFT";
			this->button_InvertDFT->Size = System::Drawing::Size(118, 35);
			this->button_InvertDFT->TabIndex = 22;
			this->button_InvertDFT->Text = L"invert DFT";
			this->button_InvertDFT->UseVisualStyleBackColor = true;
			this->button_InvertDFT->Click += gcnew System::EventHandler(this, &Hauptfenster::Button_InvertDFT_Click);
			// 
			// button_RecenterDFT
			// 
			this->button_RecenterDFT->Enabled = false;
			this->button_RecenterDFT->Location = System::Drawing::Point(345, 25);
			this->button_RecenterDFT->Name = L"button_RecenterDFT";
			this->button_RecenterDFT->Size = System::Drawing::Size(118, 35);
			this->button_RecenterDFT->TabIndex = 21;
			this->button_RecenterDFT->Text = L"recenter DFT";
			this->button_RecenterDFT->UseVisualStyleBackColor = true;
			this->button_RecenterDFT->Click += gcnew System::EventHandler(this, &Hauptfenster::Button_RecenterDFT_Click);
			// 
			// textBox_InvertDFT
			// 
			this->textBox_InvertDFT->BackColor = System::Drawing::SystemColors::Control;
			this->textBox_InvertDFT->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox_InvertDFT->Location = System::Drawing::Point(670, 396);
			this->textBox_InvertDFT->Multiline = true;
			this->textBox_InvertDFT->Name = L"textBox_InvertDFT";
			this->textBox_InvertDFT->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox_InvertDFT->Size = System::Drawing::Size(300, 143);
			this->textBox_InvertDFT->TabIndex = 20;
			// 
			// textBox_RecenterDFT
			// 
			this->textBox_RecenterDFT->BackColor = System::Drawing::SystemColors::Control;
			this->textBox_RecenterDFT->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox_RecenterDFT->Location = System::Drawing::Point(345, 396);
			this->textBox_RecenterDFT->Multiline = true;
			this->textBox_RecenterDFT->Name = L"textBox_RecenterDFT";
			this->textBox_RecenterDFT->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox_RecenterDFT->Size = System::Drawing::Size(300, 143);
			this->textBox_RecenterDFT->TabIndex = 19;
			// 
			// textBox_VisualizeDFT
			// 
			this->textBox_VisualizeDFT->BackColor = System::Drawing::SystemColors::Control;
			this->textBox_VisualizeDFT->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox_VisualizeDFT->Location = System::Drawing::Point(21, 396);
			this->textBox_VisualizeDFT->Multiline = true;
			this->textBox_VisualizeDFT->Name = L"textBox_VisualizeDFT";
			this->textBox_VisualizeDFT->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox_VisualizeDFT->Size = System::Drawing::Size(300, 143);
			this->textBox_VisualizeDFT->TabIndex = 18;
			// 
			// button_VisualizeDFT
			// 
			this->button_VisualizeDFT->Enabled = false;
			this->button_VisualizeDFT->Location = System::Drawing::Point(21, 25);
			this->button_VisualizeDFT->Name = L"button_VisualizeDFT";
			this->button_VisualizeDFT->Size = System::Drawing::Size(118, 35);
			this->button_VisualizeDFT->TabIndex = 15;
			this->button_VisualizeDFT->Text = L"visualize DFT";
			this->button_VisualizeDFT->UseVisualStyleBackColor = true;
			this->button_VisualizeDFT->Click += gcnew System::EventHandler(this, &Hauptfenster::Button_VisualizeDFT_Click);
			// 
			// tabPage4
			// 
			this->tabPage4->BackColor = System::Drawing::SystemColors::Control;
			this->tabPage4->Controls->Add(this->textBox_CreateHistogram);
			this->tabPage4->Controls->Add(this->button_CreateHistogram);
			this->tabPage4->Controls->Add(this->panel_CreateHistogram);
			this->tabPage4->Location = System::Drawing::Point(4, 27);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Padding = System::Windows::Forms::Padding(3);
			this->tabPage4->Size = System::Drawing::Size(991, 638);
			this->tabPage4->TabIndex = 3;
			this->tabPage4->Text = L"Histogram";
			// 
			// textBox_CreateHistogram
			// 
			this->textBox_CreateHistogram->BackColor = System::Drawing::SystemColors::Control;
			this->textBox_CreateHistogram->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox_CreateHistogram->Location = System::Drawing::Point(19, 387);
			this->textBox_CreateHistogram->Multiline = true;
			this->textBox_CreateHistogram->Name = L"textBox_CreateHistogram";
			this->textBox_CreateHistogram->Size = System::Drawing::Size(575, 150);
			this->textBox_CreateHistogram->TabIndex = 17;
			// 
			// button_CreateHistogram
			// 
			this->button_CreateHistogram->Location = System::Drawing::Point(19, 16);
			this->button_CreateHistogram->Name = L"button_CreateHistogram";
			this->button_CreateHistogram->Size = System::Drawing::Size(160, 35);
			this->button_CreateHistogram->TabIndex = 16;
			this->button_CreateHistogram->Text = L"create histogram";
			this->button_CreateHistogram->UseVisualStyleBackColor = true;
			this->button_CreateHistogram->Click += gcnew System::EventHandler(this, &Hauptfenster::Button_CreateHistogram_Click);
			// 
			// panel_CreateHistogram
			// 
			this->panel_CreateHistogram->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->panel_CreateHistogram->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_CreateHistogram->Location = System::Drawing::Point(19, 67);
			this->panel_CreateHistogram->Name = L"panel_CreateHistogram";
			this->panel_CreateHistogram->Size = System::Drawing::Size(575, 300);
			this->panel_CreateHistogram->TabIndex = 0;
			// 
			// tabPage5
			// 
			this->tabPage5->BackColor = System::Drawing::SystemColors::Control;
			this->tabPage5->Controls->Add(this->panel_CartoonizeEffect);
			this->tabPage5->Controls->Add(this->panel_LomographyFilter);
			this->tabPage5->Controls->Add(this->panel_EqualizeImageColor);
			this->tabPage5->Controls->Add(this->button_CartoonizeEffect);
			this->tabPage5->Controls->Add(this->button_LomographyEffect);
			this->tabPage5->Controls->Add(this->textBox11);
			this->tabPage5->Controls->Add(this->textBox12);
			this->tabPage5->Controls->Add(this->textBox13);
			this->tabPage5->Controls->Add(this->button_EqualizeImageColor);
			this->tabPage5->Location = System::Drawing::Point(4, 27);
			this->tabPage5->Name = L"tabPage5";
			this->tabPage5->Padding = System::Windows::Forms::Padding(3);
			this->tabPage5->Size = System::Drawing::Size(991, 638);
			this->tabPage5->TabIndex = 4;
			this->tabPage5->Text = L"Apply Filters";
			// 
			// panel_CartoonizeEffect
			// 
			this->panel_CartoonizeEffect->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->panel_CartoonizeEffect->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_CartoonizeEffect->Location = System::Drawing::Point(670, 82);
			this->panel_CartoonizeEffect->Name = L"panel_CartoonizeEffect";
			this->panel_CartoonizeEffect->Size = System::Drawing::Size(300, 300);
			this->panel_CartoonizeEffect->TabIndex = 29;
			// 
			// panel_LomographyFilter
			// 
			this->panel_LomographyFilter->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->panel_LomographyFilter->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_LomographyFilter->Location = System::Drawing::Point(345, 82);
			this->panel_LomographyFilter->Name = L"panel_LomographyFilter";
			this->panel_LomographyFilter->Size = System::Drawing::Size(300, 300);
			this->panel_LomographyFilter->TabIndex = 28;
			// 
			// panel_EqualizeImageColor
			// 
			this->panel_EqualizeImageColor->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->panel_EqualizeImageColor->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_EqualizeImageColor->Location = System::Drawing::Point(24, 82);
			this->panel_EqualizeImageColor->Name = L"panel_EqualizeImageColor";
			this->panel_EqualizeImageColor->Size = System::Drawing::Size(300, 300);
			this->panel_EqualizeImageColor->TabIndex = 27;
			// 
			// button_CartoonizeEffect
			// 
			this->button_CartoonizeEffect->Enabled = false;
			this->button_CartoonizeEffect->Location = System::Drawing::Point(670, 25);
			this->button_CartoonizeEffect->Name = L"button_CartoonizeEffect";
			this->button_CartoonizeEffect->Size = System::Drawing::Size(169, 35);
			this->button_CartoonizeEffect->TabIndex = 26;
			this->button_CartoonizeEffect->Text = L"cartoonize effect";
			this->button_CartoonizeEffect->UseVisualStyleBackColor = true;
			this->button_CartoonizeEffect->Click += gcnew System::EventHandler(this, &Hauptfenster::Button_CartoonizeEffect_Click);
			// 
			// button_LomographyEffect
			// 
			this->button_LomographyEffect->Enabled = false;
			this->button_LomographyEffect->Location = System::Drawing::Point(345, 25);
			this->button_LomographyEffect->Name = L"button_LomographyEffect";
			this->button_LomographyEffect->Size = System::Drawing::Size(167, 35);
			this->button_LomographyEffect->TabIndex = 25;
			this->button_LomographyEffect->Text = L"lomography effect";
			this->button_LomographyEffect->UseVisualStyleBackColor = true;
			this->button_LomographyEffect->Click += gcnew System::EventHandler(this, &Hauptfenster::Button_LomographyEffect_Click);
			// 
			// textBox11
			// 
			this->textBox11->BackColor = System::Drawing::SystemColors::Control;
			this->textBox11->Location = System::Drawing::Point(670, 396);
			this->textBox11->Multiline = true;
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(300, 150);
			this->textBox11->TabIndex = 24;
			// 
			// textBox12
			// 
			this->textBox12->BackColor = System::Drawing::SystemColors::Control;
			this->textBox12->Location = System::Drawing::Point(345, 396);
			this->textBox12->Multiline = true;
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(300, 150);
			this->textBox12->TabIndex = 22;
			// 
			// textBox13
			// 
			this->textBox13->BackColor = System::Drawing::SystemColors::Control;
			this->textBox13->Location = System::Drawing::Point(21, 396);
			this->textBox13->Multiline = true;
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(300, 150);
			this->textBox13->TabIndex = 21;
			// 
			// button_EqualizeImageColor
			// 
			this->button_EqualizeImageColor->Enabled = false;
			this->button_EqualizeImageColor->Location = System::Drawing::Point(21, 25);
			this->button_EqualizeImageColor->Name = L"button_EqualizeImageColor";
			this->button_EqualizeImageColor->Size = System::Drawing::Size(171, 35);
			this->button_EqualizeImageColor->TabIndex = 17;
			this->button_EqualizeImageColor->Text = L"equalize image color";
			this->button_EqualizeImageColor->UseVisualStyleBackColor = true;
			this->button_EqualizeImageColor->Click += gcnew System::EventHandler(this, &Hauptfenster::Button_EqualizeImageColor_Click);
			// 
			// tabPage6
			// 
			this->tabPage6->BackColor = System::Drawing::SystemColors::Control;
			this->tabPage6->Controls->Add(this->textBox_RemoveLightAndThreshold);
			this->tabPage6->Controls->Add(this->textBox_LoadLightPattern);
			this->tabPage6->Controls->Add(this->panel_RemoveLightAndThreshold);
			this->tabPage6->Controls->Add(this->checkBox_Method_Normalize_i);
			this->tabPage6->Controls->Add(this->label8);
			this->tabPage6->Controls->Add(this->label7);
			this->tabPage6->Controls->Add(this->label6);
			this->tabPage6->Controls->Add(this->label5);
			this->tabPage6->Controls->Add(this->label4);
			this->tabPage6->Controls->Add(this->panel_ProcessLightPattern_2);
			this->tabPage6->Controls->Add(this->panel_ProcessLightPattern_1);
			this->tabPage6->Controls->Add(this->checkBox_Method_Normalize_ii);
			this->tabPage6->Controls->Add(this->panel_ProcessLightPattern_5);
			this->tabPage6->Controls->Add(this->panel_ProcessLightPattern_4);
			this->tabPage6->Controls->Add(this->panel_ProcessLightPattern_3);
			this->tabPage6->Controls->Add(this->button_RemoveLightAndThreshold);
			this->tabPage6->Controls->Add(this->label3);
			this->tabPage6->Controls->Add(this->button_ProcessLightPattern);
			this->tabPage6->Controls->Add(this->label2);
			this->tabPage6->Controls->Add(this->label1);
			this->tabPage6->Controls->Add(this->button_LoadLightPatternImage);
			this->tabPage6->Controls->Add(this->panel_LoadLightPattern);
			this->tabPage6->Controls->Add(this->label_NoiseRemoval);
			this->tabPage6->Controls->Add(this->panel_NoiseRemoval);
			this->tabPage6->Controls->Add(this->trackBar_NoiseRemovalIndex);
			this->tabPage6->Controls->Add(this->checkBox_ImgProcessingBlur);
			this->tabPage6->Controls->Add(this->checkBox_ImgProcessingMedianBlur);
			this->tabPage6->Controls->Add(this->textBox_NoiseRemoval);
			this->tabPage6->Controls->Add(this->button_NoiseRemoval);
			this->tabPage6->Location = System::Drawing::Point(4, 27);
			this->tabPage6->Name = L"tabPage6";
			this->tabPage6->Padding = System::Windows::Forms::Padding(3);
			this->tabPage6->Size = System::Drawing::Size(991, 638);
			this->tabPage6->TabIndex = 5;
			this->tabPage6->Text = L"1. ML Image Pre-processing ";
			// 
			// textBox_RemoveLightAndThreshold
			// 
			this->textBox_RemoveLightAndThreshold->BackColor = System::Drawing::SystemColors::Control;
			this->textBox_RemoveLightAndThreshold->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->textBox_RemoveLightAndThreshold->Location = System::Drawing::Point(662, 418);
			this->textBox_RemoveLightAndThreshold->Multiline = true;
			this->textBox_RemoveLightAndThreshold->Name = L"textBox_RemoveLightAndThreshold";
			this->textBox_RemoveLightAndThreshold->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox_RemoveLightAndThreshold->Size = System::Drawing::Size(300, 88);
			this->textBox_RemoveLightAndThreshold->TabIndex = 51;
			// 
			// textBox_LoadLightPattern
			// 
			this->textBox_LoadLightPattern->BackColor = System::Drawing::SystemColors::Control;
			this->textBox_LoadLightPattern->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox_LoadLightPattern->Location = System::Drawing::Point(343, 418);
			this->textBox_LoadLightPattern->Multiline = true;
			this->textBox_LoadLightPattern->Name = L"textBox_LoadLightPattern";
			this->textBox_LoadLightPattern->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox_LoadLightPattern->Size = System::Drawing::Size(300, 88);
			this->textBox_LoadLightPattern->TabIndex = 50;
			// 
			// panel_RemoveLightAndThreshold
			// 
			this->panel_RemoveLightAndThreshold->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->panel_RemoveLightAndThreshold->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_RemoveLightAndThreshold->Location = System::Drawing::Point(662, 102);
			this->panel_RemoveLightAndThreshold->Name = L"panel_RemoveLightAndThreshold";
			this->panel_RemoveLightAndThreshold->Size = System::Drawing::Size(300, 300);
			this->panel_RemoveLightAndThreshold->TabIndex = 36;
			// 
			// checkBox_Method_Normalize_i
			// 
			this->checkBox_Method_Normalize_i->AutoSize = true;
			this->checkBox_Method_Normalize_i->Location = System::Drawing::Point(662, 77);
			this->checkBox_Method_Normalize_i->Name = L"checkBox_Method_Normalize_i";
			this->checkBox_Method_Normalize_i->Size = System::Drawing::Size(102, 22);
			this->checkBox_Method_Normalize_i->TabIndex = 49;
			this->checkBox_Method_Normalize_i->Text = L"Normalize";
			this->checkBox_Method_Normalize_i->UseVisualStyleBackColor = true;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(743, 519);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(23, 18);
			this->label8->TabIndex = 48;
			this->label8->Text = L"5.";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(644, 520);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(23, 18);
			this->label7->TabIndex = 47;
			this->label7->Text = L"4.";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(546, 519);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(23, 18);
			this->label6->TabIndex = 46;
			this->label6->Text = L"3.";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(447, 519);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(23, 18);
			this->label5->TabIndex = 45;
			this->label5->Text = L"2.";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(348, 519);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(23, 18);
			this->label4->TabIndex = 44;
			this->label4->Text = L"1.";
			// 
			// panel_ProcessLightPattern_2
			// 
			this->panel_ProcessLightPattern_2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->panel_ProcessLightPattern_2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_ProcessLightPattern_2->Location = System::Drawing::Point(450, 542);
			this->panel_ProcessLightPattern_2->Name = L"panel_ProcessLightPattern_2";
			this->panel_ProcessLightPattern_2->Size = System::Drawing::Size(94, 73);
			this->panel_ProcessLightPattern_2->TabIndex = 43;
			// 
			// panel_ProcessLightPattern_1
			// 
			this->panel_ProcessLightPattern_1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->panel_ProcessLightPattern_1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_ProcessLightPattern_1->Location = System::Drawing::Point(351, 542);
			this->panel_ProcessLightPattern_1->Name = L"panel_ProcessLightPattern_1";
			this->panel_ProcessLightPattern_1->Size = System::Drawing::Size(94, 73);
			this->panel_ProcessLightPattern_1->TabIndex = 42;
			// 
			// checkBox_Method_Normalize_ii
			// 
			this->checkBox_Method_Normalize_ii->AutoSize = true;
			this->checkBox_Method_Normalize_ii->Location = System::Drawing::Point(26, 593);
			this->checkBox_Method_Normalize_ii->Name = L"checkBox_Method_Normalize_ii";
			this->checkBox_Method_Normalize_ii->Size = System::Drawing::Size(102, 22);
			this->checkBox_Method_Normalize_ii->TabIndex = 41;
			this->checkBox_Method_Normalize_ii->Text = L"Normalize";
			this->checkBox_Method_Normalize_ii->UseVisualStyleBackColor = true;
			// 
			// panel_ProcessLightPattern_5
			// 
			this->panel_ProcessLightPattern_5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->panel_ProcessLightPattern_5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_ProcessLightPattern_5->Location = System::Drawing::Point(746, 542);
			this->panel_ProcessLightPattern_5->Name = L"panel_ProcessLightPattern_5";
			this->panel_ProcessLightPattern_5->Size = System::Drawing::Size(94, 73);
			this->panel_ProcessLightPattern_5->TabIndex = 40;
			// 
			// panel_ProcessLightPattern_4
			// 
			this->panel_ProcessLightPattern_4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->panel_ProcessLightPattern_4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_ProcessLightPattern_4->Location = System::Drawing::Point(647, 542);
			this->panel_ProcessLightPattern_4->Name = L"panel_ProcessLightPattern_4";
			this->panel_ProcessLightPattern_4->Size = System::Drawing::Size(94, 73);
			this->panel_ProcessLightPattern_4->TabIndex = 39;
			// 
			// panel_ProcessLightPattern_3
			// 
			this->panel_ProcessLightPattern_3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->panel_ProcessLightPattern_3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_ProcessLightPattern_3->Location = System::Drawing::Point(549, 542);
			this->panel_ProcessLightPattern_3->Name = L"panel_ProcessLightPattern_3";
			this->panel_ProcessLightPattern_3->Size = System::Drawing::Size(94, 73);
			this->panel_ProcessLightPattern_3->TabIndex = 38;
			// 
			// button_RemoveLightAndThreshold
			// 
			this->button_RemoveLightAndThreshold->Enabled = false;
			this->button_RemoveLightAndThreshold->Location = System::Drawing::Point(662, 40);
			this->button_RemoveLightAndThreshold->Name = L"button_RemoveLightAndThreshold";
			this->button_RemoveLightAndThreshold->Size = System::Drawing::Size(236, 35);
			this->button_RemoveLightAndThreshold->TabIndex = 37;
			this->button_RemoveLightAndThreshold->Text = L"remove light and threshold";
			this->button_RemoveLightAndThreshold->UseVisualStyleBackColor = true;
			this->button_RemoveLightAndThreshold->Click += gcnew System::EventHandler(this, &Hauptfenster::Button_RemoveLightAndThreshold_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(663, 12);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(322, 18);
			this->label3->TabIndex = 35;
			this->label3->Text = L"4 and 5. Remove light and apply threshold";
			// 
			// button_ProcessLightPattern
			// 
			this->button_ProcessLightPattern->Enabled = false;
			this->button_ProcessLightPattern->Location = System::Drawing::Point(27, 542);
			this->button_ProcessLightPattern->Name = L"button_ProcessLightPattern";
			this->button_ProcessLightPattern->Size = System::Drawing::Size(296, 43);
			this->button_ProcessLightPattern->TabIndex = 34;
			this->button_ProcessLightPattern->Text = L"show the entire process";
			this->button_ProcessLightPattern->UseVisualStyleBackColor = true;
			this->button_ProcessLightPattern->Click += gcnew System::EventHandler(this, &Hauptfenster::Button_ProcessLightPattern_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(340, 13);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(158, 18);
			this->label2->TabIndex = 33;
			this->label2->Text = L"3. Load light pattern";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(23, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(136, 18);
			this->label1->TabIndex = 32;
			this->label1->Text = L"2. Remove Noise";
			// 
			// button_LoadLightPatternImage
			// 
			this->button_LoadLightPatternImage->Enabled = false;
			this->button_LoadLightPatternImage->Location = System::Drawing::Point(343, 40);
			this->button_LoadLightPatternImage->Name = L"button_LoadLightPatternImage";
			this->button_LoadLightPatternImage->Size = System::Drawing::Size(155, 35);
			this->button_LoadLightPatternImage->TabIndex = 31;
			this->button_LoadLightPatternImage->Text = L"load light pattern";
			this->button_LoadLightPatternImage->UseVisualStyleBackColor = true;
			this->button_LoadLightPatternImage->Click += gcnew System::EventHandler(this, &Hauptfenster::Button_LoadLightPatternImage_Click);
			// 
			// panel_LoadLightPattern
			// 
			this->panel_LoadLightPattern->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->panel_LoadLightPattern->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_LoadLightPattern->Location = System::Drawing::Point(343, 102);
			this->panel_LoadLightPattern->Name = L"panel_LoadLightPattern";
			this->panel_LoadLightPattern->Size = System::Drawing::Size(300, 300);
			this->panel_LoadLightPattern->TabIndex = 30;
			// 
			// label_NoiseRemoval
			// 
			this->label_NoiseRemoval->AutoSize = true;
			this->label_NoiseRemoval->Location = System::Drawing::Point(305, 57);
			this->label_NoiseRemoval->Name = L"label_NoiseRemoval";
			this->label_NoiseRemoval->Size = System::Drawing::Size(18, 18);
			this->label_NoiseRemoval->TabIndex = 29;
			this->label_NoiseRemoval->Text = L"1";
			// 
			// panel_NoiseRemoval
			// 
			this->panel_NoiseRemoval->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->panel_NoiseRemoval->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_NoiseRemoval->Location = System::Drawing::Point(23, 102);
			this->panel_NoiseRemoval->Name = L"panel_NoiseRemoval";
			this->panel_NoiseRemoval->Size = System::Drawing::Size(300, 300);
			this->panel_NoiseRemoval->TabIndex = 28;
			// 
			// trackBar_NoiseRemovalIndex
			// 
			this->trackBar_NoiseRemovalIndex->LargeChange = 1;
			this->trackBar_NoiseRemovalIndex->Location = System::Drawing::Point(219, 57);
			this->trackBar_NoiseRemovalIndex->Minimum = 1;
			this->trackBar_NoiseRemovalIndex->Name = L"trackBar_NoiseRemovalIndex";
			this->trackBar_NoiseRemovalIndex->Size = System::Drawing::Size(80, 45);
			this->trackBar_NoiseRemovalIndex->TabIndex = 27;
			this->trackBar_NoiseRemovalIndex->Value = 1;
			this->trackBar_NoiseRemovalIndex->Scroll += gcnew System::EventHandler(this, &Hauptfenster::trackBar_NoiseRemovalIndex_Scroll);
			// 
			// checkBox_ImgProcessingBlur
			// 
			this->checkBox_ImgProcessingBlur->AutoSize = true;
			this->checkBox_ImgProcessingBlur->Location = System::Drawing::Point(158, 53);
			this->checkBox_ImgProcessingBlur->Name = L"checkBox_ImgProcessingBlur";
			this->checkBox_ImgProcessingBlur->Size = System::Drawing::Size(55, 22);
			this->checkBox_ImgProcessingBlur->TabIndex = 26;
			this->checkBox_ImgProcessingBlur->Text = L"Blur";
			this->checkBox_ImgProcessingBlur->UseVisualStyleBackColor = true;
			this->checkBox_ImgProcessingBlur->CheckedChanged += gcnew System::EventHandler(this, &Hauptfenster::CheckBox_ImgProcessingBlur_Click);
			// 
			// checkBox_ImgProcessingMedianBlur
			// 
			this->checkBox_ImgProcessingMedianBlur->AutoSize = true;
			this->checkBox_ImgProcessingMedianBlur->Location = System::Drawing::Point(158, 31);
			this->checkBox_ImgProcessingMedianBlur->Name = L"checkBox_ImgProcessingMedianBlur";
			this->checkBox_ImgProcessingMedianBlur->Size = System::Drawing::Size(112, 22);
			this->checkBox_ImgProcessingMedianBlur->TabIndex = 25;
			this->checkBox_ImgProcessingMedianBlur->Text = L"Median Blur";
			this->checkBox_ImgProcessingMedianBlur->UseVisualStyleBackColor = true;
			this->checkBox_ImgProcessingMedianBlur->CheckedChanged += gcnew System::EventHandler(this, &Hauptfenster::CheckBox_ImgProcessingMedianBlur_Click);
			// 
			// textBox_NoiseRemoval
			// 
			this->textBox_NoiseRemoval->BackColor = System::Drawing::SystemColors::Control;
			this->textBox_NoiseRemoval->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox_NoiseRemoval->Location = System::Drawing::Point(23, 418);
			this->textBox_NoiseRemoval->Multiline = true;
			this->textBox_NoiseRemoval->Name = L"textBox_NoiseRemoval";
			this->textBox_NoiseRemoval->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox_NoiseRemoval->Size = System::Drawing::Size(300, 88);
			this->textBox_NoiseRemoval->TabIndex = 24;
			// 
			// button_NoiseRemoval
			// 
			this->button_NoiseRemoval->Enabled = false;
			this->button_NoiseRemoval->Location = System::Drawing::Point(23, 40);
			this->button_NoiseRemoval->Name = L"button_NoiseRemoval";
			this->button_NoiseRemoval->Size = System::Drawing::Size(129, 35);
			this->button_NoiseRemoval->TabIndex = 23;
			this->button_NoiseRemoval->Text = L"noise removal";
			this->button_NoiseRemoval->UseVisualStyleBackColor = true;
			this->button_NoiseRemoval->Click += gcnew System::EventHandler(this, &Hauptfenster::Button_NoiseRemoval_Click);
			// 
			// tabPage7
			// 
			this->tabPage7->BackColor = System::Drawing::SystemColors::Control;
			this->tabPage7->Controls->Add(this->checkBox_Method_Normalize_iii);
			this->tabPage7->Controls->Add(this->label11);
			this->tabPage7->Controls->Add(this->panel_BasicContours);
			this->tabPage7->Controls->Add(this->textBox_BasicContours);
			this->tabPage7->Controls->Add(this->label9);
			this->tabPage7->Controls->Add(this->panel_ConnectedComponents);
			this->tabPage7->Controls->Add(this->textBox_ConnectedComponents);
			this->tabPage7->Controls->Add(this->button_RunSegmentationAlgorithms);
			this->tabPage7->Location = System::Drawing::Point(4, 27);
			this->tabPage7->Name = L"tabPage7";
			this->tabPage7->Padding = System::Windows::Forms::Padding(3);
			this->tabPage7->Size = System::Drawing::Size(991, 638);
			this->tabPage7->TabIndex = 6;
			this->tabPage7->Text = L"2. ML Segmentation";
			// 
			// checkBox_Method_Normalize_iii
			// 
			this->checkBox_Method_Normalize_iii->AutoSize = true;
			this->checkBox_Method_Normalize_iii->Location = System::Drawing::Point(283, 15);
			this->checkBox_Method_Normalize_iii->Name = L"checkBox_Method_Normalize_iii";
			this->checkBox_Method_Normalize_iii->Size = System::Drawing::Size(102, 22);
			this->checkBox_Method_Normalize_iii->TabIndex = 50;
			this->checkBox_Method_Normalize_iii->Text = L"Normalize";
			this->checkBox_Method_Normalize_iii->UseVisualStyleBackColor = true;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(340, 57);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(188, 18);
			this->label11->TabIndex = 39;
			this->label11->Text = L"Find Contours Algorithm";
			// 
			// panel_BasicContours
			// 
			this->panel_BasicContours->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->panel_BasicContours->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_BasicContours->Location = System::Drawing::Point(343, 82);
			this->panel_BasicContours->Name = L"panel_BasicContours";
			this->panel_BasicContours->Size = System::Drawing::Size(300, 300);
			this->panel_BasicContours->TabIndex = 38;
			// 
			// textBox_BasicContours
			// 
			this->textBox_BasicContours->BackColor = System::Drawing::SystemColors::Control;
			this->textBox_BasicContours->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox_BasicContours->Location = System::Drawing::Point(343, 396);
			this->textBox_BasicContours->Multiline = true;
			this->textBox_BasicContours->Name = L"textBox_BasicContours";
			this->textBox_BasicContours->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox_BasicContours->Size = System::Drawing::Size(300, 129);
			this->textBox_BasicContours->TabIndex = 37;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(22, 57);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(265, 18);
			this->label9->TabIndex = 35;
			this->label9->Text = L"Connected Components Algorithm";
			// 
			// panel_ConnectedComponents
			// 
			this->panel_ConnectedComponents->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->panel_ConnectedComponents->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_ConnectedComponents->Location = System::Drawing::Point(25, 82);
			this->panel_ConnectedComponents->Name = L"panel_ConnectedComponents";
			this->panel_ConnectedComponents->Size = System::Drawing::Size(300, 300);
			this->panel_ConnectedComponents->TabIndex = 33;
			// 
			// textBox_ConnectedComponents
			// 
			this->textBox_ConnectedComponents->BackColor = System::Drawing::SystemColors::Control;
			this->textBox_ConnectedComponents->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox_ConnectedComponents->Location = System::Drawing::Point(25, 396);
			this->textBox_ConnectedComponents->Multiline = true;
			this->textBox_ConnectedComponents->Name = L"textBox_ConnectedComponents";
			this->textBox_ConnectedComponents->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox_ConnectedComponents->Size = System::Drawing::Size(300, 129);
			this->textBox_ConnectedComponents->TabIndex = 30;
			// 
			// button_RunSegmentationAlgorithms
			// 
			this->button_RunSegmentationAlgorithms->Enabled = false;
			this->button_RunSegmentationAlgorithms->Location = System::Drawing::Point(25, 15);
			this->button_RunSegmentationAlgorithms->Name = L"button_RunSegmentationAlgorithms";
			this->button_RunSegmentationAlgorithms->Size = System::Drawing::Size(252, 35);
			this->button_RunSegmentationAlgorithms->TabIndex = 29;
			this->button_RunSegmentationAlgorithms->Text = L"run segmentation algorithms";
			this->button_RunSegmentationAlgorithms->UseVisualStyleBackColor = true;
			this->button_RunSegmentationAlgorithms->Click += gcnew System::EventHandler(this, &Hauptfenster::Button_RunSegmentationAlgorithms_Click);
			// 
			// textBox_MainImage
			// 
			this->textBox_MainImage->BackColor = System::Drawing::SystemColors::Control;
			this->textBox_MainImage->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->textBox_MainImage->Location = System::Drawing::Point(15, 428);
			this->textBox_MainImage->Multiline = true;
			this->textBox_MainImage->Name = L"textBox_MainImage";
			this->textBox_MainImage->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox_MainImage->Size = System::Drawing::Size(300, 150);
			this->textBox_MainImage->TabIndex = 12;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// panel_MainImage
			// 
			this->panel_MainImage->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->panel_MainImage->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_MainImage->Location = System::Drawing::Point(15, 109);
			this->panel_MainImage->Name = L"panel_MainImage";
			this->panel_MainImage->Size = System::Drawing::Size(300, 300);
			this->panel_MainImage->TabIndex = 29;
			// 
			// Hauptfenster
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1355, 686);
			this->Controls->Add(this->panel_MainImage);
			this->Controls->Add(this->textBox_MainImage);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->button_LoadImage);
			this->Name = L"Hauptfenster";
			this->Text = L"Hauptfenster";
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_BlurIndex))->EndInit();
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			this->tabPage4->ResumeLayout(false);
			this->tabPage4->PerformLayout();
			this->tabPage5->ResumeLayout(false);
			this->tabPage5->PerformLayout();
			this->tabPage6->ResumeLayout(false);
			this->tabPage6->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_NoiseRemovalIndex))->EndInit();
			this->tabPage7->ResumeLayout(false);
			this->tabPage7->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Button_LoadImage_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Button_LoadLightPatternImage_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Button_GrayFilter_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void trackBar_BlurIndex_Scroll(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Button_BlurFilter_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Button_SplitChannels_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Button_RemoveBGR_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Button_Sobel_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Button_VisualizeDFT_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Button_RecenterDFT_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Button_InvertDFT_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Button_CreateHistogram_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Button_EqualizeImageColor_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Button_LomographyEffect_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Button_CartoonizeEffect_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Button_NoiseRemoval_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void trackBar_NoiseRemovalIndex_Scroll(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Button_RemoveLightAndThreshold_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Button_ProcessLightPattern_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Button_RunSegmentationAlgorithms_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void CheckBox_ImgProcessingMedianBlur_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void CheckBox_ImgProcessingBlur_Click(System::Object^ sender, System::EventArgs^ e);
	// ---------
	private: char* convertManagedStringToANSIFormat(System::String^ str);
	private: cv::Mat resizeMatImageObject(Mat img, int divisor);
	private: cv::Mat removeChannel(Mat img, int channel, int depth);
	private: cv::Mat createDiscreetFourierTransformObject(Mat input);
	private: cv::Mat convertDFTObjectToLogarithmicScaleAndNormalize(Mat input);
	private: cv::Mat recenterDiscreetFourierTransformObject(Mat input);
	private: cv::Mat invertDiscreetFourierTransformObject(Mat input);
	private: string matType2str(int type);
	private: cv::Mat calculateLightPattern(Mat img);
	private: cv::Mat removeLight(Mat img, Mat pattern, int method);
	private: cv::Mat ConnectedComponents(Mat img);
	private: cv::Mat ConnectedComponentsStats(Mat img);
	private: cv::Mat FindContoursBasic(Mat img);
	private: static Scalar randomColor(RNG& rng);
	private: System::Void enableDisableButtons(System::String^ str);
};
}
