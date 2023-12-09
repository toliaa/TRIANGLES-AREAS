#include "Main-Triangle.h"

#include <cmath>

using namespace System;
using namespace System::Windows::Forms;

// Abstract base class for triangles
ref class Triangle abstract
{
public:
    virtual double CalculateArea() abstract;
};

// Concrete implementation based on three vertices
ref class VertexTriangle : public Triangle
{
private:
    double x1, y1, x2, y2, x3, y3;

public:
    VertexTriangle(double x1, double y1, double x2, double y2, double x3, double y3)
        : x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3) {}

    // Implementation of calculateArea for VertexTriangle
    virtual double CalculateArea() override
    {
        return 0.5 * Math::Abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
    }
};

// Concrete implementation based on three sides
ref class SideTriangle : public Triangle
{
private:
    double side1, side2, side3;

public:
    SideTriangle(double side1, double side2, double side3)
        : side1(side1), side2(side2), side3(side3) {}

    // Implementation of calculateArea for SideTriangle
    virtual double CalculateArea() override
    {
        double s = (side1 + side2 + side3) / 2.0;
        return Math::Sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }
};

// Windows Forms Application
ref class TriangleForm : public Form
{
private:
    TextBox^ vertexInputs;
    TextBox^ sideInputs;
    Button^ calculateVertexButton;
    Button^ calculateSideButton;

public:
    TriangleForm()
    {
        InitializeComponents();
    }

private:
    void InitializeComponents()
    {
        vertexInputs = gcnew TextBox();
        vertexInputs->Multiline = true;
        vertexInputs->Dock = DockStyle::Top;
        vertexInputs->Height = 60;
        vertexInputs->Text = "Enter Vertex Coordinates (x1, y1, x2, y2, x3, y3)";

        sideInputs = gcnew TextBox();
        sideInputs->Multiline = true;
        sideInputs->Dock = DockStyle::Top;
        sideInputs->Height = 60;
        sideInputs->Text = "Enter Side Lengths (side1, side2, side3)";

        calculateVertexButton = gcnew Button();
        calculateVertexButton->Text = "Calculate VertexTriangle Area";
        calculateVertexButton->Dock = DockStyle::Top;
        calculateVertexButton->Click += gcnew EventHandler(this, &TriangleForm::CalculateVertexButton_Click);

        calculateSideButton = gcnew Button();
        calculateSideButton->Text = "Calculate SideTriangle Area";
        calculateSideButton->Dock = DockStyle::Top;
        calculateSideButton->Click += gcnew EventHandler(this, &TriangleForm::CalculateSideButton_Click);

        Controls->Add(vertexInputs);
        Controls->Add(calculateVertexButton);
        Controls->Add(sideInputs);
        Controls->Add(calculateSideButton);
    }

    void CalculateVertexButton_Click(Object^ sender, EventArgs^ e)
    {
        try
        {
            array<String^>^ vertexParams = vertexInputs->Text->Split(',');
            double x1 = Convert::ToDouble(vertexParams[0]);
            double y1 = Convert::ToDouble(vertexParams[1]);
            double x2 = Convert::ToDouble(vertexParams[2]);
            double y2 = Convert::ToDouble(vertexParams[3]);
            double x3 = Convert::ToDouble(vertexParams[4]);
            double y3 = Convert::ToDouble(vertexParams[5]);

            VertexTriangle^ vertexTriangle = gcnew VertexTriangle(x1, y1, x2, y2, x3, y3);

            MessageBox::Show(String::Format("Area of VertexTriangle: {0}", vertexTriangle->CalculateArea()),
                "Triangle Area", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
        catch (Exception^ ex)
        {
            MessageBox::Show(String::Format("Error: {0}", ex->Message), "Error",
                MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    void CalculateSideButton_Click(Object^ sender, EventArgs^ e)
    {
        try
        {
            array<String^>^ sideParams = sideInputs->Text->Split(',');
            double side1 = Convert::ToDouble(sideParams[0]);
            double side2 = Convert::ToDouble(sideParams[1]);
            double side3 = Convert::ToDouble(sideParams[2]);

            SideTriangle^ sideTriangle = gcnew SideTriangle(side1, side2, side3);

            MessageBox::Show(String::Format("Area of SideTriangle: {0}", sideTriangle->CalculateArea()),
                "Triangle Area", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
        catch (Exception^ ex)
        {
            MessageBox::Show(String::Format("Error: {0}", ex->Message), "Error",
                MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }
};

int main(array<System::String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    Application::Run(gcnew TriangleForm());

    return 0;
}

