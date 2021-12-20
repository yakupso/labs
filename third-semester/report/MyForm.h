#pragma once
#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <msclr/marshal_cppstd.h>
#include <msclr/marshal.h>

#include "LR_7_1.h"
#include "LR_7_2.h"
#include "LR_8_1.h"
#include "LR_8_2.h"

namespace myblatantproject {
	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Diagnostics;

	ListDL<string> list1;
	ListDL<int> list2;
	ListDL<double> list3;
	myQueue<string> queue1;
	myQueue<int> queue2;
	myQueue<double> queue3;
	myStack<string> stack1;
	myStack<int> stack2;
	myStack<double> stack3;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TreeView^ treeView;
	public: System::Windows::Forms::RichTextBox^ code_box;




	private: System::Windows::Forms::OpenFileDialog^ open_file_dialog;
	private: System::Windows::Forms::SaveFileDialog^ save_file_dialog;
	private: System::Windows::Forms::ToolStrip^ toolStrip;
	private: System::Windows::Forms::ToolStripButton^ toolStripOpenFile;
	private: System::Windows::Forms::ToolStripButton^ toolStripLoadOut;
	private: System::Windows::Forms::ToolStripButton^ toolStripTest;
	private: System::Windows::Forms::ToolStripButton^ toolStripClear;
	private: System::Windows::Forms::ToolStripButton^ toolStripSaveFile;
	private: System::Windows::Forms::ComboBox^ comboBox;

	private: System::Windows::Forms::TextBox^ textKey;
	private: System::Windows::Forms::Button^ buttonRemove;
	private: System::Windows::Forms::Button^ buttonInsert;



	private: System::Windows::Forms::TextBox^ textValue;
	private: System::Windows::Forms::Panel^ panel;





	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::TreeNode^ treeNode1 = (gcnew System::Windows::Forms::TreeNode(L"Часть 1"));
			System::Windows::Forms::TreeNode^ treeNode2 = (gcnew System::Windows::Forms::TreeNode(L"Часть 2"));
			System::Windows::Forms::TreeNode^ treeNode3 = (gcnew System::Windows::Forms::TreeNode(L"Лабораторная работа №7", gcnew cli::array< System::Windows::Forms::TreeNode^  >(2) {
				treeNode1,
					treeNode2
			}));
			System::Windows::Forms::TreeNode^ treeNode4 = (gcnew System::Windows::Forms::TreeNode(L"Часть 1"));
			System::Windows::Forms::TreeNode^ treeNode5 = (gcnew System::Windows::Forms::TreeNode(L"Часть 2"));
			System::Windows::Forms::TreeNode^ treeNode6 = (gcnew System::Windows::Forms::TreeNode(L"Лабораторная работа №8", gcnew cli::array< System::Windows::Forms::TreeNode^  >(2) {
				treeNode4,
					treeNode5
			}));
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->treeView = (gcnew System::Windows::Forms::TreeView());
			this->code_box = (gcnew System::Windows::Forms::RichTextBox());
			this->open_file_dialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->save_file_dialog = (gcnew System::Windows::Forms::SaveFileDialog());
			this->toolStrip = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripOpenFile = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSaveFile = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripTest = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripLoadOut = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripClear = (gcnew System::Windows::Forms::ToolStripButton());
			this->comboBox = (gcnew System::Windows::Forms::ComboBox());
			this->textKey = (gcnew System::Windows::Forms::TextBox());
			this->buttonRemove = (gcnew System::Windows::Forms::Button());
			this->buttonInsert = (gcnew System::Windows::Forms::Button());
			this->textValue = (gcnew System::Windows::Forms::TextBox());
			this->panel = (gcnew System::Windows::Forms::Panel());
			this->toolStrip->SuspendLayout();
			this->panel->SuspendLayout();
			this->SuspendLayout();
			// 
			// treeView
			// 
			this->treeView->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->treeView->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->treeView->Location = System::Drawing::Point(35, 28);
			this->treeView->Name = L"treeView";
			treeNode1->Name = L"LR_7_1";
			treeNode1->Tag = L"LR_7_1";
			treeNode1->Text = L"Часть 1";
			treeNode2->Name = L"LR_7_2";
			treeNode2->Tag = L"LR_7_2";
			treeNode2->Text = L"Часть 2";
			treeNode3->Name = L"LR_7";
			treeNode3->Tag = L"LR_7";
			treeNode3->Text = L"Лабораторная работа №7";
			treeNode4->Name = L"LR_8_1";
			treeNode4->Tag = L"LR_8_1";
			treeNode4->Text = L"Часть 1";
			treeNode5->Name = L"LR_8_2";
			treeNode5->Tag = L"LR_8_2";
			treeNode5->Text = L"Часть 2";
			treeNode6->Name = L"LR_8";
			treeNode6->Tag = L"LR_8";
			treeNode6->Text = L"Лабораторная работа №8";
			this->treeView->Nodes->AddRange(gcnew cli::array< System::Windows::Forms::TreeNode^  >(2) { treeNode3, treeNode6 });
			this->treeView->Size = System::Drawing::Size(315, 444);
			this->treeView->TabIndex = 0;
			this->treeView->AfterSelect += gcnew System::Windows::Forms::TreeViewEventHandler(this, &MyForm::treeView_AfterSelect);
			// 
			// code_box
			// 
			this->code_box->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->code_box->Font = (gcnew System::Drawing::Font(L"DejaVu Sans Mono", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->code_box->Location = System::Drawing::Point(385, 28);
			this->code_box->Name = L"code_box";
			this->code_box->Size = System::Drawing::Size(815, 591);
			this->code_box->TabIndex = 1;
			this->code_box->Text = L"";
			// 
			// open_file_dialog
			// 
			this->open_file_dialog->FileName = L"OpenFileDialog";
			// 
			// save_file_dialog
			// 
			this->save_file_dialog->FileName = L"Save As";
			// 
			// toolStrip
			// 
			this->toolStrip->GripMargin = System::Windows::Forms::Padding(0);
			this->toolStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->toolStripOpenFile,
					this->toolStripSaveFile, this->toolStripTest, this->toolStripLoadOut, this->toolStripClear
			});
			this->toolStrip->Location = System::Drawing::Point(0, 0);
			this->toolStrip->Name = L"toolStrip";
			this->toolStrip->Size = System::Drawing::Size(1240, 25);
			this->toolStrip->TabIndex = 11;
			this->toolStrip->Text = L"toolStrip";
			// 
			// toolStripOpenFile
			// 
			this->toolStripOpenFile->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripOpenFile.Image")));
			this->toolStripOpenFile->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripOpenFile->Name = L"toolStripOpenFile";
			this->toolStripOpenFile->Size = System::Drawing::Size(77, 22);
			this->toolStripOpenFile->Text = L"Open File";
			this->toolStripOpenFile->ToolTipText = L"Open File";
			this->toolStripOpenFile->Click += gcnew System::EventHandler(this, &MyForm::toolStripOpenFile_Click);
			// 
			// toolStripSaveFile
			// 
			this->toolStripSaveFile->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripSaveFile.Image")));
			this->toolStripSaveFile->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripSaveFile->Name = L"toolStripSaveFile";
			this->toolStripSaveFile->Size = System::Drawing::Size(72, 22);
			this->toolStripSaveFile->Text = L"Save File";
			this->toolStripSaveFile->Click += gcnew System::EventHandler(this, &MyForm::toolStripSaveFile_Click);
			// 
			// toolStripTest
			// 
			this->toolStripTest->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripTest.Image")));
			this->toolStripTest->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripTest->Name = L"toolStripTest";
			this->toolStripTest->Size = System::Drawing::Size(47, 22);
			this->toolStripTest->Text = L"Test";
			this->toolStripTest->Click += gcnew System::EventHandler(this, &MyForm::toolStripTest_Click);
			// 
			// toolStripLoadOut
			// 
			this->toolStripLoadOut->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripLoadOut.Image")));
			this->toolStripLoadOut->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripLoadOut->Name = L"toolStripLoadOut";
			this->toolStripLoadOut->Size = System::Drawing::Size(76, 22);
			this->toolStripLoadOut->Text = L"Load Out";
			this->toolStripLoadOut->Click += gcnew System::EventHandler(this, &MyForm::toolStripLoadOut_Click);
			// 
			// toolStripClear
			// 
			this->toolStripClear->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripClear.Image")));
			this->toolStripClear->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripClear->Name = L"toolStripClear";
			this->toolStripClear->Size = System::Drawing::Size(54, 22);
			this->toolStripClear->Text = L"Clear";
			this->toolStripClear->Click += gcnew System::EventHandler(this, &MyForm::toolStripClear_Click);
			// 
			// comboBox
			// 
			this->comboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBox->FormattingEnabled = true;
			this->comboBox->Items->AddRange(gcnew cli::array< System::Object^  >(9) {
				L"ListDL<string>", L"ListDL<int>", L"ListDL<double>",
					L"Queue<string>", L"Queue<int>", L"Queue<double>", L"Stack<string>", L"Stack<int>", L"Stack<double>"
			});
			this->comboBox->Location = System::Drawing::Point(0, 35);
			this->comboBox->MaxDropDownItems = 9;
			this->comboBox->Name = L"comboBox";
			this->comboBox->Size = System::Drawing::Size(315, 32);
			this->comboBox->TabIndex = 13;
			//this->comboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox_SelectedIndexChanged);
			// 
			// textKey
			// 
			this->textKey->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textKey->Location = System::Drawing::Point(0, 0);
			this->textKey->Name = L"textKey";
			this->textKey->Size = System::Drawing::Size(141, 29);
			this->textKey->TabIndex = 14;
			this->textKey->Text = L"Key";
			// 
			// buttonRemove
			// 
			this->buttonRemove->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonRemove->Location = System::Drawing::Point(0, 80);
			this->buttonRemove->Name = L"buttonRemove";
			this->buttonRemove->Size = System::Drawing::Size(141, 35);
			this->buttonRemove->TabIndex = 16;
			this->buttonRemove->Text = L"Remove";
			this->buttonRemove->UseVisualStyleBackColor = true;
			this->buttonRemove->Click += gcnew System::EventHandler(this, &MyForm::buttonRemove_Click);
			// 
			// buttonInsert
			// 
			this->buttonInsert->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonInsert->Location = System::Drawing::Point(174, 80);
			this->buttonInsert->Name = L"buttonInsert";
			this->buttonInsert->Size = System::Drawing::Size(141, 35);
			this->buttonInsert->TabIndex = 18;
			this->buttonInsert->Text = L"Insert";
			this->buttonInsert->UseVisualStyleBackColor = true;
			this->buttonInsert->Click += gcnew System::EventHandler(this, &MyForm::buttonInsert_Click);
			// 
			// textValue
			// 
			this->textValue->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textValue->Location = System::Drawing::Point(174, 0);
			this->textValue->Name = L"textValue";
			this->textValue->Size = System::Drawing::Size(141, 29);
			this->textValue->TabIndex = 17;
			this->textValue->Text = L"Value";
			// 
			// panel
			// 
			this->panel->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->panel->Controls->Add(this->buttonRemove);
			this->panel->Controls->Add(this->comboBox);
			this->panel->Controls->Add(this->buttonInsert);
			this->panel->Controls->Add(this->textKey);
			this->panel->Controls->Add(this->textValue);
			this->panel->Location = System::Drawing::Point(35, 504);
			this->panel->Name = L"panel";
			this->panel->Size = System::Drawing::Size(315, 115);
			this->panel->TabIndex = 19;
			this->panel->Visible = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->ClientSize = System::Drawing::Size(1240, 662);
			this->Controls->Add(this->panel);
			this->Controls->Add(this->toolStrip);
			this->Controls->Add(this->code_box);
			this->Controls->Add(this->treeView);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"Yakupso\'s Labs";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->toolStrip->ResumeLayout(false);
			this->toolStrip->PerformLayout();
			this->panel->ResumeLayout(false);
			this->panel->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		// Clear
	private: System::Void toolStripClear_Click(System::Object^ sender, System::EventArgs^ e) {
		code_box->Clear();
	}

		   // Open
	private: System::Void toolStripOpenFile_Click(System::Object^ sender, System::EventArgs^ e) {
		wchar_t path[MAX_PATH];
		GetCurrentDirectory(sizeof(path), path);

		OpenFileDialog^ open_file_dialog = gcnew OpenFileDialog;
		open_file_dialog->InitialDirectory = Convert::ToString(path);
		open_file_dialog->Filter = "All files|*.*";
		open_file_dialog->FilterIndex = 2;
		open_file_dialog->RestoreDirectory = true;
		if (open_file_dialog->ShowDialog() == Windows::Forms::DialogResult::OK) {
			code_box->Text = File::ReadAllText(open_file_dialog->FileName);
		}
	}

	private: System::Void treeView_AfterSelect(System::Object^ sender, System::Windows::Forms::TreeViewEventArgs^ e) {
		if ((e->Node->Name == "LR_7") || (e->Node->Name == "LR_7_1")) {
			panel->Visible = false;
			this->treeView->Size = System::Drawing::Size(315, 591);
			code_box->Text = File::ReadAllText("TT7_1.txt");
		}
		else if (e->Node->Name == "LR_7_2") {
			panel->Visible = false;
			this->treeView->Size = System::Drawing::Size(315, 591);
			code_box->Text = File::ReadAllText("TT7_2.txt");
		}
		else if ((e->Node->Name == "LR_8") || (e->Node->Name == "LR_8_1")) {
			panel->Visible = false;
			this->treeView->Size = System::Drawing::Size(315, 591);
			code_box->Text = File::ReadAllText("TT8_1.txt");
		}
		else if (e->Node->Name == "LR_8_2") {
			panel->Visible = true;
			this->treeView->Size = System::Drawing::Size(315, 444);
			code_box->Text = File::ReadAllText("TT8_2.txt");
		}
	}

		   // Save
	private: System::Void toolStripSaveFile_Click(System::Object^ sender, System::EventArgs^ e) {
		wchar_t path[MAX_PATH];
		GetCurrentDirectory(sizeof(path), path);
		SaveFileDialog^ saveFileDialog = gcnew SaveFileDialog();
		saveFileDialog->InitialDirectory = Convert::ToString(path);
		saveFileDialog->Filter = "All Files|*.*";
		if (saveFileDialog->ShowDialog() == Windows::Forms::DialogResult::OK) {
			File::WriteAllText(saveFileDialog->FileName, code_box->Text);
		}
	}

		   // Test
	private: System::Void toolStripTest_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ name = Convert::ToString(treeView->SelectedNode->Tag);
		if (name == "LR_7_1")
			lr_7_1();
		else if (name == "LR_7_2")
			lr_7_2();
		else if (name == "LR_8_1")
			lr_8_1();
		else if (name == "LR_8_2")
			if (comboBox->SelectedItem->ToString() == "ListDL<string>")
				list1 = lr_8_2_list_string();
			else if (comboBox->SelectedItem->ToString() == "ListDL<int>")
				list2 = lr_8_2_list_int();
			else if (comboBox->SelectedItem->ToString() == "ListDL<double>")
				list3 = lr_8_2_list_double();
			else if (comboBox->SelectedItem->ToString() == "Queue<string>")
				queue1 = lr_8_2_queue_string();
			else if (comboBox->SelectedItem->ToString() == "Queue<int>")
				queue2 = lr_8_2_queue_int();
			else if (comboBox->SelectedItem->ToString() == "Queue<double>")
				queue3 = lr_8_2_queue_double();
			else if (comboBox->SelectedItem->ToString() == "Stack<string>")
				stack1 = lr_8_2_stack_string();
			else if (comboBox->SelectedItem->ToString() == "Stack<int>")
				stack2 = lr_8_2_stack_int();
			else if (comboBox->SelectedItem->ToString() == "Stack<double>")
				stack3 = lr_8_2_stack_double();
			else
				return;
		//switch (msclr::interop::marshal_as<std::string>(comboBox->SelectedItem)) {

	}

	private: System::Void toolStripLoadOut_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ file;
		code_box->Clear();
		file = Convert::ToString(treeView->SelectedNode->Tag);
		if (file == "LR_7" || file == "LR_8") {
			code_box->Text = "Select Criterion";
			return;
		}
		file = file + ".txt";
		pin_ptr<const wchar_t> str1 = PtrToStringChars(file);
		ifstream iff(str1);
		if (!iff) {
			code_box->Text = "Click button \"test\"";
		}
		else {
			code_box->Text = System::IO::File::ReadAllText(file);
		}
	}

	public: void lr_7_1() {
		srand(time(NULL));
		const int v = 28;
		double 	random_num;
		Figurez* figures[v];

		for (int i = 0; i < v; i++) {
			random_num = myrandz(0.0, 1.0);
			if (random_num <= 0.5)
				figures[i] = new Circlez();
			else
				figures[i] = new Rectanglez();
		}

		// Обнуляем файл или создаём его, если его нет.
		ofstream new_fout("LR_7_1.txt"); new_fout.close();
		// Открываем поток.
		ofstream fout("LR_7_1.txt", ios_base::app);
		if (fout) {
			for (int i = 0; i < v; i++)
				fout << *figures[i] << endl;

			fout << "\nTotal rectangles: " << Rectanglez::RECTANGLEz_COUNT << endl;
			fout << "\nTotal circles: " << Circlez::CIRCLEz_COUNT << endl;
			fout.close();
		}
	}

	public: void lr_7_2() {
		srand(time(NULL));
		Field field;

		ofstream new_fout("LR_7_2.txt"); new_fout.close();
		// Открываем поток.
		ofstream fout("LR_7_2.txt", ios_base::app);

		if (fout) {
			fout << "\nTotal rectangles: " << Rectangleo::RECTANGLEo_COUNT << endl;
			fout << "Total circles: " << Circleo::CIRCLEo_COUNT << endl;
			for (double time = 0.; time <= 5.; time += 0.1) {
				fout << "\nTime: " << time << endl;
				for (int i = 0; i < K; i++) {
					auto& elem = field.get_figureos()[i];
					fout << "\n\t" << (i + 1) << ") " << *elem;
				}
				fout << "\n---------------------------------------"
					<< "----------------------------------------\n\n";
				Figureo** figures = field.ticking();
			}
		}
	}

	public: void lr_8_1() {
		srand(time(NULL));
		int k = 10;

		// Инициализация четырех массивов:
		int* integers = new int[k];
		for (int i = 0; i < k; i++)
			integers[i] = rand() % k;
		double* doubles = new double[k];
		for (int i = 0; i < k; i++)
			doubles[i] = (double)(rand()) / (RAND_MAX / k);
		Square_8_1* squares = new Square_8_1[k];
		Circle_8_1* circles = new Circle_8_1[k];

		ofstream new_fout("LR_8_1.txt"); new_fout.close();
		// Открываем поток.
		ofstream fout("LR_8_1.txt", ios_base::app);
		if (fout) {
			// Вывод содержимого всех массивов:
			fout << "\nIntegers: ";
			for (int i = 0; i < k; i++)
				fout << integers[i] << ' ';
			fout << "\nDoubles: ";
			for (int i = 0; i < k; i++)
				fout << doubles[i] << ' ';
			fout << "\nSquares: ";
			for (int i = 0; i < k; i++)
				fout << squares[i] << ' ';
			fout << "\nCircles: ";
			for (int i = 0; i < k; i++)
				fout << circles[i] << ' ';

			// Сортировка каждого массива и их вывод:
			pyramid_sort(integers);
			pyramid_sort(doubles);
			pyramid_sort(squares);
			pyramid_sort(circles);
			fout << "\n\nIntegers (sorted): ";
			for (int i = 0; i < k; i++)
				fout << integers[i] << ' ';
			fout << "\nDoubles (sorted): ";
			for (int i = 0; i < k; i++)
				fout << doubles[i] << ' ';
			fout << "\nSquares (sorted): ";
			for (int i = 0; i < k; i++)
				fout << squares[i] << ' ';
			fout << "\nCircles (sorted): ";
			for (int i = 0; i < k; i++)
				fout << circles[i] << ' ';

			// Вывод среднего каждого массива:
			fout << "\n\nAverage of integers: " << average(integers);
			fout << "\nAverage of doubles: " << average(doubles);
			fout << "\nAverage of squares: " << average(squares);
			fout << "\nAverage of circles: " << average(circles) << endl;
		}

	}

	public: ListDL<string> lr_8_2_list_string() {
		ofstream new_fout("LR_8_2.txt"); new_fout.close();
		ofstream fout("LR_8_2.txt", ios_base::app);
		ListDL<string> list1;
		string key1, k1, data1;
		Node<string>* n0 = new Node<string>();
		n0->key = "zero";
		n0->data = "Aa";
		list1.push_back(n0);
		Node<string>* n1 = new Node<string>();
		n1->key = "one";
		n1->data = "Bb";
		list1.push_back(n1);
		Node<string>* n2 = new Node<string>();
		n2->key = "two";
		n2->data = "Cc";
		list1.push_back(n2);
		Node<string>* n3 = new Node<string>();
		n3->key = "three";
		n3->data = "Dd";
		list1.push_back(n3);
		Node<string>* n4 = new Node<string>();
		n4->key = "four";
		n4->data = "Ee";
		list1.push_back(n4);
		Node<string>* n5 = new Node<string>();
		n5->key = "five";
		n5->data = "Ff";
		list1.push_back(n5);
		Node<string>* n6 = new Node<string>();
		n6->key = "six";
		n6->data = "Gg";
		list1.push_back(n6);
		Node<string>* n7 = new Node<string>();
		n7->key = "seven";
		n7->data = "Hh";
		list1.push_back(n7);
		Node<string>* n8 = new Node<string>();
		n8->key = "eight";
		n8->data = "Ii";
		list1.push_back(n8);
		Node<string>* n9 = new Node<string>();
		n9->key = "nine";
		n9->data = "Jj";
		list1.push_back(n9);
		Node<string>* n10 = new Node<string>();
		n10->key = "ten";
		n10->data = "Kk";
		list1.push_back(n10);

		list1.print_list();
		fout.close();
		return list1;
	}

	public: ListDL<int> lr_8_2_list_int() {
		ofstream new_fout("LR_8_2.txt"); new_fout.close();
		ofstream fout("LR_8_2.txt", ios_base::app);
		ListDL<int> list2;
		int key2, data2;
		for (int i = 0; i <= 10; i++) {
			Node<int>* n11 = new Node<int>();
			n11->key = i;
			n11->data = i * i * i;
			list2.push_back(n11);
		}
		list2.print_list();
		fout.close();
		return list2;
	}
	
	public: ListDL<double> lr_8_2_list_double() {
		ofstream new_fout("LR_8_2.txt"); new_fout.close();
		ofstream fout("LR_8_2.txt", ios_base::app);
		fout << "\n\n\nList<double>";
		fout.close();
		ListDL<double> list3;
		double key3, data3;
		for (double d = 0; d <= 10; d++) {
			Node<double>* n3 = new Node<double>();
			n3->key = d;
			n3->data = d * 3.14;
			list3.push_back(n3);
		}
		list3.print_list();
		fout.close();
		return list3;
	}
	
	public: myQueue<string> lr_8_2_queue_string() {
		ofstream new_fout("LR_8_2.txt"); new_fout.close();
		ofstream fout("LR_8_2.txt", ios_base::app);
		myQueue<string> queue1;
		Node<string>* n0 = new Node<string>();
		n0->key = "zero";
		n0->data = "Aa";
		queue1.push_back(n0);
		Node<string>* n1 = new Node<string>();
		n1->key = "one";
		n1->data = "Bb";
		queue1.push_back(n1);
		Node<string>* n2 = new Node<string>();
		n2->key = "two";
		n2->data = "Cc";
		queue1.push_back(n2);
		Node<string>* n3 = new Node<string>();
		n3->key = "three";
		n3->data = "Dd";
		queue1.push_back(n3);
		Node<string>* n4 = new Node<string>();
		n4->key = "four";
		n4->data = "Ee";
		queue1.push_back(n4);
		Node<string>* n5 = new Node<string>();
		n5->key = "five";
		n5->data = "Ff";
		queue1.push_back(n5);
		Node<string>* n6 = new Node<string>();
		n6->key = "six";
		n6->data = "Gg";
		queue1.push_back(n6);
		Node<string>* n7 = new Node<string>();
		n7->key = "seven";
		n7->data = "Hh";
		queue1.push_back(n7);
		Node<string>* n8 = new Node<string>();
		n8->key = "eight";
		n8->data = "Ii";
		queue1.push_back(n8);
		Node<string>* n9 = new Node<string>();
		n9->key = "nine";
		n9->data = "Jj";
		queue1.push_back(n9);
		Node<string>* n10 = new Node<string>();
		n10->key = "ten";
		n10->data = "Kk";
		queue1.push_back(n10);
		queue1.print_list();
		fout.close();
		return queue1;
	}

	public: myQueue<int> lr_8_2_queue_int() {
		ofstream new_fout("LR_8_2.txt"); new_fout.close();
		ofstream fout("LR_8_2.txt", ios_base::app);
		myQueue<int> queue2;
		for (int i = 0; i <= 10; i++) {
			Node<int>* n11 = new Node<int>();
			n11->key = i;
			n11->data = i * i * i;
			queue2.push_back(n11);
		}
		queue2.print_list();
		fout.close();
		return queue2;
	}

	public: myQueue<double> lr_8_2_queue_double() {
		ofstream new_fout("LR_8_2.txt"); new_fout.close();
		ofstream fout("LR_8_2.txt", ios_base::app);
		myQueue<double> queue3;
		for (double d = 0; d <= 10; d++) {
			Node<double>* n3 = new Node<double>();
			n3->key = d;
			n3->data = d * 3.14;
			queue3.push_back(n3);
		}
		queue3.print_list();
		fout.close();
		return queue3;
	}

	public: myStack<string> lr_8_2_stack_string() {
		ofstream new_fout("LR_8_2.txt"); new_fout.close();
		ofstream fout("LR_8_2.txt", ios_base::app);
		myStack<string> stack1;
		Node<string>* n0 = new Node<string>();
		n0->key = "zero";
		n0->data = "Aa";
		stack1.push_back(n0);
		Node<string>* n1 = new Node<string>();
		n1->key = "one";
		n1->data = "Bb";
		stack1.push_back(n1);
		Node<string>* n2 = new Node<string>();
		n2->key = "two";
		n2->data = "Cc";
		stack1.push_back(n2);
		Node<string>* n3 = new Node<string>();
		n3->key = "three";
		n3->data = "Dd";
		stack1.push_back(n3);
		Node<string>* n4 = new Node<string>();
		n4->key = "four";
		n4->data = "Ee";
		stack1.push_back(n4);
		Node<string>* n5 = new Node<string>();
		n5->key = "five";
		n5->data = "Ff";
		stack1.push_back(n5);
		Node<string>* n6 = new Node<string>();
		n6->key = "six";
		n6->data = "Gg";
		stack1.push_back(n6);
		Node<string>* n7 = new Node<string>();
		n7->key = "seven";
		n7->data = "Hh";
		stack1.push_back(n7);
		Node<string>* n8 = new Node<string>();
		n8->key = "eight";
		n8->data = "Ii";
		stack1.push_back(n8);
		Node<string>* n9 = new Node<string>();
		n9->key = "nine";
		n9->data = "Jj";
		stack1.push_back(n9);
		Node<string>* n10 = new Node<string>();
		n10->key = "ten";
		n10->data = "Kk";
		stack1.push_back(n10);
		stack1.print_list();
		fout.close();

		return stack1;
	}

	public: myStack<int> lr_8_2_stack_int() {
		ofstream new_fout("LR_8_2.txt"); new_fout.close();
		ofstream fout("LR_8_2.txt", ios_base::app);
		myStack<int> stack2;
		for (int i = 0; i <= 10; i++) {
			Node<int>* n11 = new Node<int>();
			n11->key = i;
			n11->data = i * i * i;
			stack2.push_back(n11);
		}
		stack2.print_list();
		fout.close();
		return stack2;
	}

	public: myStack<double> lr_8_2_stack_double() {
		ofstream new_fout("LR_8_2.txt"); new_fout.close();
		ofstream fout("LR_8_2.txt", ios_base::app);
		myStack<double> stack3;
		for (double d = 0; d <= 10; d++) {
			Node<double>* n3 = new Node<double>();
			n3->key = d;
			n3->data = d * 3.14;
			stack3.push_back(n3);
		}
		stack3.print_list();
		stack3.remove_node(3.);
		stack3.print_list();
		fout.close();
		return stack3;
	}

		
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	comboBox->SelectedItem = "ListDL<string>";
}

private: System::Void buttonRemove_Click(System::Object^ sender, System::EventArgs^ e) {
	if (comboBox->SelectedItem->ToString() == "ListDL<string>") {
		list1.remove_node(msclr::interop::marshal_as<std::string>(textKey->Text));
		ofstream fout("LR_8_2.txt", ios_base::out);
		list1.print_list();
		fout.close();
	}
	else if (comboBox->SelectedItem->ToString() == "ListDL<int>") {
		list2.remove_node(stoi(msclr::interop::marshal_as<std::string>(textKey->Text)));
		ofstream fout("LR_8_2.txt", ios_base::out);
		list2.print_list();
		fout.close();
	}
	else if (comboBox->SelectedItem->ToString() == "ListDL<double>") {
		list3.remove_node(stod(msclr::interop::marshal_as<std::string>(textKey->Text)));
		ofstream fout("LR_8_2.txt", ios_base::out);
		list3.print_list();
		fout.close();
	}
	else if (comboBox->SelectedItem->ToString() == "Queue<string>") {
		queue1.remove_node(msclr::interop::marshal_as<std::string>(textKey->Text));
		ofstream fout("LR_8_2.txt", ios_base::out);
		queue1.print_list();
		fout.close();
	}
	else if (comboBox->SelectedItem->ToString() == "Queue<int>") {
		queue2.remove_node(stoi(msclr::interop::marshal_as<std::string>(textKey->Text)));
		ofstream fout("LR_8_2.txt", ios_base::out);
		queue2.print_list();
		fout.close();
	}
	else if (comboBox->SelectedItem->ToString() == "Queue<double>") {
		queue3.remove_node(stod(msclr::interop::marshal_as<std::string>(textKey->Text)));
		ofstream fout("LR_8_2.txt", ios_base::out);
		queue3.print_list();
		fout.close();
	}
	else if (comboBox->SelectedItem->ToString() == "Stack<string>") {
		stack1.remove_node(msclr::interop::marshal_as<std::string>(textKey->Text));
		ofstream fout("LR_8_2.txt", ios_base::out);
		stack1.print_list();
		fout.close();
	}
	else if (comboBox->SelectedItem->ToString() == "Stack<int>") {
		stack2.remove_node(stoi(msclr::interop::marshal_as<std::string>(textKey->Text)));
		ofstream fout("LR_8_2.txt", ios_base::out);
		stack2.print_list();
		fout.close();
	}
	else if (comboBox->SelectedItem->ToString() == "Stack<double>") {
		stack3.remove_node(stod(msclr::interop::marshal_as<std::string>(textKey->Text)));
		ofstream fout("LR_8_2.txt", ios_base::out);
		stack3.print_list();
		fout.close();
	}
	else
		return;
}

private: System::Void buttonInsert_Click(System::Object^ sender, System::EventArgs^ e) {
	if (comboBox->SelectedItem->ToString() == "ListDL<string>") {
		Node<string> *n = new Node<string>();
		n->key = msclr::interop::marshal_as<std::string>(textKey->Text);
		n->data = msclr::interop::marshal_as<std::string>(textValue->Text);
		list1.push_back(n);
		ofstream fout("LR_8_2.txt", ios_base::out);
		list1.print_list();
		fout.close();
	}
	else if (comboBox->SelectedItem->ToString() == "ListDL<int>") {
		Node<int>* n = new Node<int>();
		n->key = stoi(msclr::interop::marshal_as<std::string>(textKey->Text));
		n->data = stoi(msclr::interop::marshal_as<std::string>(textValue->Text));
		list2.push_back(n);
		ofstream fout("LR_8_2.txt", ios_base::out);
		list2.print_list();
		fout.close();
	}
	else if (comboBox->SelectedItem->ToString() == "ListDL<double>") {
		Node<double> *n = new Node<double>();
		n->key = stod(msclr::interop::marshal_as<std::string>(textKey->Text));
		n->data = stod(msclr::interop::marshal_as<std::string>(textValue->Text));
		list3.push_back(n);
		ofstream fout("LR_8_2.txt", ios_base::out);
		list3.print_list();
		fout.close();
	}
	else if (comboBox->SelectedItem->ToString() == "Queue<string>") {
		Node<string> *n = new Node<string>();
		n->key = msclr::interop::marshal_as<std::string>(textKey->Text);
		n->data = msclr::interop::marshal_as<std::string>(textValue->Text);
		queue1.push_back(n);
		ofstream fout("LR_8_2.txt", ios_base::out);
		queue1.print_list();
		fout.close();
	}
	else if (comboBox->SelectedItem->ToString() == "Queue<int>") {
		Node<int>* n = new Node<int>();
		n->key = stoi(msclr::interop::marshal_as<std::string>(textKey->Text));
		n->data = stoi(msclr::interop::marshal_as<std::string>(textValue->Text));
		queue2.push_back(n);
		ofstream fout("LR_8_2.txt", ios_base::out);
		queue2.print_list();
		fout.close();
	}
	else if (comboBox->SelectedItem->ToString() == "Queue<double>") {
		Node<double> *n = new Node<double>();
		n->key = stod(msclr::interop::marshal_as<std::string>(textKey->Text));
		n->data = stod(msclr::interop::marshal_as<std::string>(textValue->Text));
		queue3.push_back(n);
		ofstream fout("LR_8_2.txt", ios_base::out);
		queue3.print_list();
		fout.close();
	}
	else if (comboBox->SelectedItem->ToString() == "Stack<string>") {
		Node<string> *n = new Node<string>();
		n->key = msclr::interop::marshal_as<std::string>(textKey->Text);
		n->data = msclr::interop::marshal_as<std::string>(textValue->Text);
		stack1.push_back(n);
		ofstream fout("LR_8_2.txt", ios_base::out);
		stack1.print_list();
		fout.close();
	}
	else if (comboBox->SelectedItem->ToString() == "Stack<int>") {
		Node<int>* n = new Node<int>();
		n->key = stoi(msclr::interop::marshal_as<std::string>(textKey->Text));
		n->data = stoi(msclr::interop::marshal_as<std::string>(textValue->Text));
		stack2.push_back(n);
		ofstream fout("LR_8_2.txt", ios_base::out);
		stack2.print_list();
		fout.close();
	}
	else if (comboBox->SelectedItem->ToString() == "Stack<double>") {
		Node<double> *n = new Node<double>();
		n->key = stod(msclr::interop::marshal_as<std::string>(textKey->Text));
		n->data = stod(msclr::interop::marshal_as<std::string>(textValue->Text));
		stack3.push_back(n);
		ofstream fout("LR_8_2.txt", ios_base::out);
		stack3.print_list();
		fout.close();
	}
	else
		return;
}
};
}
