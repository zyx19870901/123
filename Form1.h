#pragma once
#include "Path.h"
using namespace path;
Paths src, dst;

namespace TestPath {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Form1 摘要
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: 在此处添加构造函数代码
			//
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button_optimize;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TrackBar^  trackBar1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TrackBar^  trackBar2;
	private: System::Windows::Forms::PictureBox^  pictureBox2;

	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->button_optimize = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->trackBar2 = (gcnew System::Windows::Forms::TrackBar());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// button_optimize
			// 
			this->button_optimize->Location = System::Drawing::Point(383, 519);
			this->button_optimize->Margin = System::Windows::Forms::Padding(4);
			this->button_optimize->Name = L"button_optimize";
			this->button_optimize->Size = System::Drawing::Size(112, 33);
			this->button_optimize->TabIndex = 0;
			this->button_optimize->Text = L"优化";
			this->button_optimize->UseVisualStyleBackColor = true;
			this->button_optimize->Click += gcnew System::EventHandler(this, &Form1::button_optimize_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->trackBar1);
			this->groupBox1->Controls->Add(this->pictureBox1);
			this->groupBox1->Location = System::Drawing::Point(2, 3);
			this->groupBox1->Margin = System::Windows::Forms::Padding(4);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(4);
			this->groupBox1->Size = System::Drawing::Size(433, 494);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"规划前";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(186, 469);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(50, 17);
			this->label1->TabIndex = 2;
			this->label1->Text = L"0/100";
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(19, 432);
			this->trackBar1->Maximum = 100;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(400, 45);
			this->trackBar1->TabIndex = 1;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &Form1::trackBar1_Scroll);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(19, 25);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(400, 400);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->pictureBox2);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Controls->Add(this->trackBar2);
			this->groupBox2->Location = System::Drawing::Point(443, 3);
			this->groupBox2->Margin = System::Windows::Forms::Padding(4);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(4);
			this->groupBox2->Size = System::Drawing::Size(442, 494);
			this->groupBox2->TabIndex = 2;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"规划后";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(186, 469);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(50, 17);
			this->label2->TabIndex = 2;
			this->label2->Text = L"0/100";
			// 
			// trackBar2
			// 
			this->trackBar2->Location = System::Drawing::Point(19, 432);
			this->trackBar2->Maximum = 100;
			this->trackBar2->Name = L"trackBar2";
			this->trackBar2->Size = System::Drawing::Size(400, 45);
			this->trackBar2->TabIndex = 1;
			this->trackBar2->Scroll += gcnew System::EventHandler(this, &Form1::trackBar2_Scroll);
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->pictureBox2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox2->Location = System::Drawing::Point(19, 25);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(400, 400);
			this->pictureBox2->TabIndex = 3;
			this->pictureBox2->TabStop = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 17);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(890, 567);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button_optimize);
			this->Font = (gcnew System::Drawing::Font(L"Verdana", 10.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::Form1_Paint);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

		void draw_line(Graphics ^g, Pen^ pen, const path::Point &pt1, const path::Point &pt2)
		{
			g->DrawLine(pen, PointF(pt1.x,pt1.y), PointF(pt2.x,pt2.y));
		}
		void render(const path::Point &start_end_pt, const Paths &path, int steps, PictureBox ^pb)
		{
			path::Point pre_pt = start_end_pt;
			Bitmap  ^bm = gcnew Bitmap(400,400);
			Graphics ^g = Graphics::FromImage(bm);
			g->Clear(Color::White);
			Pen ^pen1 = gcnew Pen(Color::Black);
			Pen ^pen2 = gcnew Pen(Color::FromArgb(200,200,200,200));
			pen2->DashStyle = System::Drawing::Drawing2D::DashStyle::DashDot;
			int count = 0;
			for (int i=0; i<int(path.size()); i++)
			{
				for (int j=0; j<int(path[i].size()); j++)
				{
					if(j==0)
						draw_line(g, pen2, pre_pt, path[i][j]);
					else
						draw_line(g, pen1, pre_pt, path[i][j]);
					pre_pt = path[i][j];
					count++; if(count>steps) goto EXIT;
				}
			}
EXIT:		delete pen1;
			delete pen2;
			delete g;
			delete pb->Image;
			pb->Image = bm;
		}
		int count_steps(Paths &path)
		{
			int count = 0;
			for (int i=0; i<int(path.size()); i++)
			{
				count += path[i].size();
			}
			return count;
		}
		void show_trackbar(TrackBar ^tb, Label ^label)
		{
			String ^s = gcnew String("");
			s += Convert::ToString(tb->Value);
			s += " / ";
			s += Convert::ToString(tb->Maximum);
			label->Text = s;
		}
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
		 {
			 //////////////////////////////////////////////////////////////
			 Path t;
			 t.push_back( path::Point(185.0f,237.0f) );
			 t.push_back( path::Point(226.0f,255.0f) );
			 t.push_back( path::Point(246.0f,297.0f) );
			 t.push_back( path::Point(222.0f,336.0f) );
			 t.push_back( path::Point(117.0f,341.0f) );
			 t.push_back( path::Point(139.0f,335.0f) );
			 t.push_back( path::Point(115.0f,296.0f) );
			 t.push_back( path::Point(140.0f,251.0f) );
			 t.push_back( path::Point(185.0f,237.0f) );
			 src.push_back(t);
			 //////////////////////////////////////////////////////////////
			 t.clear();
			 t.push_back( path::Point(27.0f,187.0f) );
			 t.push_back( path::Point(130.0f,100.0f) );
			 t.push_back( path::Point(178.0f,205.0f) );
			 t.push_back( path::Point(268.0f,109.0f) );
			 t.push_back( path::Point(327.0f,210.0f) );
			 src.push_back(t);
			 ///////////////////////////////////////////////////////////////
			 t.clear();
			 t.push_back( path::Point(284.0f,70.0f) );
			 t.push_back( path::Point(212.0f,98.0f) );
			 t.push_back( path::Point(210.0f,122.0f) );
			 t.push_back( path::Point(260.0f,225.0f) );
			 src.push_back(t);
			 ///////////////////////////////////////////////////////////////
			 t.clear();
			 t.push_back( path::Point(200.0f,376.0f) );
			 t.push_back( path::Point(250.0f,355.0f) );
			 t.push_back( path::Point(315.0f,323.0f) );
			 t.push_back( path::Point(345.0f,322.0f) );
			 t.push_back( path::Point(345.0f,285.0f) );
			 t.push_back( path::Point(334.0f,263.0f) );
			 t.push_back( path::Point(315.0f,257.0f) );
			 t.push_back( path::Point(281.0f,260.0f) );
			 t.push_back( path::Point(282.0f,360.0f) );
			 t.push_back( path::Point(278.0f,381.0f) );
			 t.push_back( path::Point(217.0f,382.0f) );
			 t.push_back( path::Point(200.0f,376.0f) );
			 src.push_back(t);
			 ///////////////////////////////////////////////////////////////
			 trackBar1->Maximum = count_steps(src);
			 trackBar1->Value = trackBar1->Maximum;
			 show_trackbar(trackBar1, label1);
		 }
private: System::Void button_optimize_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 path::Point pt;
			 optimize_path(pt, src, dst);
			 trackBar2->Maximum = count_steps(dst);
			 trackBar2->Value = trackBar2->Maximum;
			 show_trackbar(trackBar2, label2);
		 }
private: System::Void Form1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) 
		 {
			 path::Point pt;
			 render(pt, src, trackBar1->Value, pictureBox1);
			 pt = path::Point(0.0f,0.0f);
			 render(pt, dst, trackBar2->Value, pictureBox2);
		 }
private: System::Void trackBar1_Scroll(System::Object^  sender, System::EventArgs^  e) 
		 {
			 path::Point pt;
			 render(pt, src, trackBar1->Value, pictureBox1);
			 show_trackbar(trackBar1, label1);
		 }
private: System::Void trackBar2_Scroll(System::Object^  sender, System::EventArgs^  e) 
		 {
			 path::Point pt;
			 render(pt, dst, trackBar2->Value, pictureBox2);
			 show_trackbar(trackBar2, label2);
		 }
};
}

