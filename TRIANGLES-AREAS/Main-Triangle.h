#pragma once

namespace TRIANGLESAREAS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainTriangle
	/// </summary>
	public ref class MainTriangle : public System::Windows::Forms::Form
	{
	public:
		MainTriangle(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainTriangle()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainTriangle::typeid));
			this->SuspendLayout();
			// 
			// MainTriangle
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(282, 253);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MainTriangle";
			this->Text = L"MainTriangle";
			this->Load += gcnew System::EventHandler(this, &MainTriangle::MainTriangle_Load);
			this->ResumeLayout(false);
			this->Icon = gcnew System::Drawing::Icon("icons.ico");
			

		}
#pragma endregion
	private: System::Void MainTriangle_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
