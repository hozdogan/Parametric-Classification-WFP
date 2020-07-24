#pragma once
#include<vector>
#include<stdlib.h>
#include <iostream>
#include <queue>
#include <time.h>
#include "Point.h"

namespace Classification {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm için özet
	/// </summary>
	std::vector<Renk> colorvec;
	Point2D* pat;
	std::vector<Point2D*> vecP;
	std::vector<Point2D*> vecCenter;
	int index,x,y,clscount;
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Oluþturucu kodunu buraya ekle
			//
		}

	protected:
		/// <summary>
		///Kullanýlan tüm kaynaklarý temizleyin.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox1;

	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label4;


	protected:

	private:
		/// <summary>
		///Gerekli tasarýmcý deðiþkeni.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Tasarýmcý desteði için gerekli metot - bu metodun 
		///içeriðini kod düzenleyici ile deðiþtirmeyin.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ControlDark;
			this->pictureBox1->Location = System::Drawing::Point(12, 31);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(500, 500);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseClick);
			this->pictureBox1->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseDoubleClick);
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseMove);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(889, 118);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(128, 39);
			this->button1->TabIndex = 1;
			this->button1->Text = L"SetÝnitialValues";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(889, 51);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 24);
			this->comboBox1->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(731, 76);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(46, 17);
			this->label1->TabIndex = 4;
			this->label1->Text = L"label1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(731, 140);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(46, 17);
			this->label2->TabIndex = 5;
			this->label2->Text = L"label2";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button3);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Location = System::Drawing::Point(1041, 95);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(284, 156);
			this->groupBox1->TabIndex = 6;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Linear Machine";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(125, 90);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(123, 37);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Linear Machine";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(25, 40);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(83, 17);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Class Count";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(125, 40);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 22);
			this->textBox1->TabIndex = 0;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(1156, 53);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 22);
			this->textBox2->TabIndex = 8;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label4->Location = System::Drawing::Point(1030, 51);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(110, 24);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Class Count";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1342, 741);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		void setInitialValues()
		{
			Renk r1(255, 0, 0);
			Renk r2(0, 0, 255);
			Renk r3(0, 255, 0);
			Renk r4(239, 163, 12);

			colorvec.push_back(r1);
			colorvec.push_back(r2);
			colorvec.push_back(r3);
			colorvec.push_back(r4);
			clscount = (int)System::Convert::ToInt32(textBox2->Text->ToString());
			comboBox1->ItemHeight = clscount;
			for (int i = 1; i <= clscount; i++)
			{
				String^ s = "Class" + i;
				comboBox1->Items->Add(s);
			}
			Graphics^ g = pictureBox1->CreateGraphics();
			Pen^ p = gcnew Pen(Color::Black, 3);
			g->DrawLine(p,0, 250, 500, 250);
			g->DrawLine(p, 250, 0, 250, 500);
		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		setInitialValues();
	}
private: System::Void pictureBox1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	Pen^ pen;
	Graphics^ g = pictureBox1->CreateGraphics();
	index = comboBox1->SelectedIndex;

	Color c = Color::FromArgb(colorvec[index].getRed(), colorvec[index].getGreen(), colorvec[index].getBlue());
	pen = gcnew Pen(c, 2);

	x = e->X - (pictureBox1->Width / 2);
	y = (pictureBox1->Height / 2) - e->Y;
	pat = new Point2D(x,y);
	pat->setClassID(index);
	vecP.push_back(pat);
	//bunun yerine çemberde olabilir
	g->DrawLine(pen, e->X - 4, e->Y, e->X + 4, e->Y);
	g->DrawLine(pen, e->X, e->Y - 4, e->X, e->Y + 4);
	
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	Pen^ pen;
	Graphics^ g = pictureBox1->CreateGraphics();
	index = comboBox1->SelectedIndex;
	ClassifiersProcess* cs = new ClassifiersProcess();
	
	Point2D* point = cs->CGCenter(vecP, index);
	Color c = Color::FromArgb(colorvec[point->getClassID()].getRed(), colorvec[point->getClassID()].getGreen(), colorvec[point->getClassID()].getBlue());
	pen = gcnew Pen(c, 2);
	g->DrawEllipse(pen,point->getX() + (pictureBox1->Width/2),(pictureBox1->Height/2)-point->getY(), 10, 10);
	delete cs;

}
private: System::Void pictureBox1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	label1->Text = "x1:" + (e->X - (pictureBox1->Width / 2)).ToString();
	label2->Text = "y1:" + ((pictureBox1->Height / 2)-e->Y).ToString();

}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	int LinearIndex = (int)System::Convert::ToInt32(textBox1->Text->ToString());
	float w0, w1, w2;
	ClassifiersProcess cs;
	Point2D* p;
	Pen^ pen;
	Graphics^ g = pictureBox1->CreateGraphics();
	for (int i = 0; i < clscount; i++)
	{
		p = cs.CGCenter(vecP, i);
		vecCenter.push_back(p);
		Color c = Color::FromArgb(colorvec[p->getClassID()].getRed(), colorvec[p->getClassID()].getGreen(), colorvec[p->getClassID()].getBlue());
		pen = gcnew Pen(c, 2);
		g->DrawEllipse(pen, p->getX() + (pictureBox1->Width / 2), (pictureBox1->Height / 2) - p->getY(), 5, 5);
	}
	for (int k = 0; k < LinearIndex; k++)
	{
		for (int j = k; j < LinearIndex; j++)
		{
			if (j == k)
				continue;
			w0 = vecCenter[k]->getX() - vecCenter[j]->getX();
			w1 = vecCenter[k]->getY() - vecCenter[j]->getY();
			w2 = cs.BTPLen(vecCenter[j], vecCenter[k]);
			Color c = Color::FromArgb(colorvec[vecCenter[k]->getClassID()].getRed(), colorvec[vecCenter[k]->getClassID()].getGreen(), colorvec[vecCenter[k]->getClassID()].getBlue());
			pen = gcnew Pen(c, 2);
			float x1 = ((-w0 * (pictureBox1->Width / 2)) - w2) / w1;
			float x2 = ((-w0 * (-pictureBox1->Width / 2)) - w2) / w1;
			g->DrawLine(pen, 500.0f, 250 - x1, 0.0f, 250 - x2);
		}
	}


}

private: System::Void pictureBox1_MouseDoubleClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	int* result = new int[clscount];
	float w0, w1, w2;
	int testX, testY;
	ClassifiersProcess cs;
	Point2D* p;
	Pen^ pen;
	Graphics^ g = pictureBox1->CreateGraphics();
	for (int i = 0; i < clscount; i++)
	{
		p = cs.CGCenter(vecP, i);
		vecCenter.push_back(p);
		Color c = Color::FromArgb(colorvec[p->getClassID()].getRed(), colorvec[p->getClassID()].getGreen(), colorvec[p->getClassID()].getBlue());
		pen = gcnew Pen(c, 2);
		g->DrawEllipse(pen, p->getX() + (pictureBox1->Width / 2), (pictureBox1->Height / 2) - p->getY(), 5, 5);
	}
	for (int k = 0; k < clscount; k++)
	{
		w0 = vecCenter[k]->getX();
		w1 = vecCenter[k]->getY();
		w2 = 0.5 * (pow(vecCenter[k]->getX(), 2) + pow(vecCenter[k]->getY(), 2)) * -1;

		testX = e->X - (pictureBox1->Width / 2);
		testY = (pictureBox1->Height / 2) - e->Y;

		result[k] = (w0 * testX) + (w1 * testY) + w2;
	}
	int max = result[0];
	int index = 0;
	for (int j = 1; j < clscount; j++)
	{
		if (result[j] > max)
		{
			max = result[j];
			index = j;
		}		
	}
	Color c = Color::FromArgb(colorvec[index].getRed(), colorvec[index].getGreen(), colorvec[index].getBlue());
	pen = gcnew Pen(c, 2);
	g->DrawLine(pen, testX + pictureBox1->Width/2,pictureBox1->Height/2 - testY,vecCenter[index]->getX()+pictureBox1->Width/2,pictureBox1->Height/2-vecCenter[index]->getY());

}
};
}
