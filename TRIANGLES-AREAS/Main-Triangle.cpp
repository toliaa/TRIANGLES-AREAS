#include "Main-Triangle.h"

#include <cmath>

#include "Main-Triangle.h"
#include <iostream>
#include <Windows.h>
#include <string>

using namespace System;
using namespace System::Windows::Forms;

#include <cmath>
#include <Windows.h>

using namespace System;
using namespace System::Windows::Forms;

// Abstract base class for triangles
ref class Triangle abstract
{
public:
    virtual double CalculateArea() abstract;
    virtual double CalculateInscribedRadius() abstract;
    virtual double CalculateCircumscribedRadius() abstract;
    virtual double CalculateMedianLength() abstract;
    virtual double CalculateParallelMedian() abstract;
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

    // Implementation of CalculateInscribedRadius for VertexTriangle
    virtual double CalculateInscribedRadius() override
    {
        double area = CalculateArea();
        double s = CalculateSemiperimeter();
        return area / s;
    }

    // Implementation of CalculateCircumscribedRadius for VertexTriangle
    virtual double CalculateCircumscribedRadius() override
    {
        double a = CalculateSideLength(x2, y2, x3, y3);
        double b = CalculateSideLength(x1, y1, x3, y3);
        double c = CalculateSideLength(x1, y1, x2, y2);
        return (a * b * c) / (4 * CalculateArea());
    }

    // Implementation of CalculateMedianLength for VertexTriangle
    virtual double CalculateMedianLength() override
    {
        // Implement the calculation of the median length for VertexTriangle
        // You can replace this with the actual formula
        return 0.0;
    }

    // Implementation of CalculateParallelMedian for VertexTriangle
    virtual double CalculateParallelMedian() override
    {
        // Implement the calculation of the parallel median for VertexTriangle
        // You can replace this with the actual formula
        return 0.0;
    }

private:
    double CalculateSemiperimeter()
    {
        double a = CalculateSideLength(x2, y2, x3, y3);
        double b = CalculateSideLength(x1, y1, x3, y3);
        double c = CalculateSideLength(x1, y1, x2, y2);
        return (a + b + c) / 2.0;
    }

    double CalculateSideLength(double x1, double y1, double x2, double y2)
    {
        return Math::Sqrt(Math::Pow(x2 - x1, 2) + Math::Pow(y2 - y1, 2));
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

    // Implementation of CalculateInscribedRadius for SideTriangle
    virtual double CalculateInscribedRadius() override
    {
        double area = CalculateArea();
        double s = CalculateSemiperimeter();
        return area / s;
    }

    // Implementation of CalculateCircumscribedRadius for SideTriangle
    virtual double CalculateCircumscribedRadius() override
    {
        double a = side1;
        double b = side2;
        double c = side3;
        return (a * b * c) / (4 * CalculateArea());
    }

    // Implementation of CalculateMedianLength for SideTriangle
    virtual double CalculateMedianLength() override
    {
        // Implement the calculation of the median length for SideTriangle
        // You can replace this with the actual formula
        return 0.0;
    }

    // Implementation of CalculateParallelMedian for SideTriangle
    virtual double CalculateParallelMedian() override
    {
        // Implement the calculation of the parallel median for SideTriangle
        // You can replace this with the actual formula
        return 0.0;
    }

private:
    double CalculateSemiperimeter()
    {
        return (side1 + side2 + side3) / 2.0;
    }
};

// Windows Forms Application
ref class TriangleForm : public Form
{
private:
    TextBox^ vertexInputs;
    TextBox^ sideInputs;
    TextBox^ inscribedRadiusOutput;
    TextBox^ circumscribedRadiusOutput;
    TextBox^ medianLengthOutput;
    TextBox^ parallelMedianOutput;
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

        inscribedRadiusOutput = gcnew TextBox();
        inscribedRadiusOutput->Multiline = true;
        inscribedRadiusOutput->Dock = DockStyle::Top;
        inscribedRadiusOutput->Height = 30;
        inscribedRadiusOutput->ReadOnly = true;
        inscribedRadiusOutput->Text = "Inscribed Radius";

        circumscribedRadiusOutput = gcnew TextBox();
        circumscribedRadiusOutput->Multiline = true;
        circumscribedRadiusOutput->Dock = DockStyle::Top;
        circumscribedRadiusOutput->Height = 30;
        circumscribedRadiusOutput->ReadOnly = true;
        circumscribedRadiusOutput->Text = "Circumscribed Radius";

        medianLengthOutput = gcnew TextBox();
        medianLengthOutput->Multiline = true;
        medianLengthOutput->Dock = DockStyle::Top;
        medianLengthOutput->Height = 30;
        medianLengthOutput->ReadOnly = true;
        medianLengthOutput->Text = "Median Length";

        parallelMedianOutput = gcnew TextBox();
        parallelMedianOutput->Multiline = true;
        parallelMedianOutput->Dock = DockStyle::Top;
        parallelMedianOutput->Height = 30;
        parallelMedianOutput->ReadOnly = true;
        parallelMedianOutput->Text = "Parallel Median";

        calculateVertexButton = gcnew Button();
        calculateVertexButton->Text = "Calculate (Vertex)";
        calculateVertexButton->Dock = DockStyle::Top;
        calculateVertexButton->Click += gcnew EventHandler(this, &TriangleForm::CalculateVertexButton_Click);

        calculateSideButton = gcnew Button();
        calculateSideButton->Text = "Calculate (Side)";
        calculateSideButton->Dock = DockStyle::Top;
        calculateSideButton->Click += gcnew EventHandler(this, &TriangleForm::CalculateSideButton_Click);

        Controls->Add(vertexInputs);
        Controls->Add(calculateVertexButton);
        Controls->Add(sideInputs);
        Controls->Add(calculateSideButton);
        Controls->Add(inscribedRadiusOutput);
        Controls->Add(circumscribedRadiusOutput);
        Controls->Add(medianLengthOutput);
        Controls->Add(parallelMedianOutput);
    }

    void CalculateVertexButton_Click(Object^ sender, EventArgs^ e)
    {
        array<String^>^ inputs = vertexInputs->Text->Split(',');

        if (inputs->Length == 6)
        {
            try
            {
                double x1 = Convert::ToDouble(inputs[0]);
                double y1 = Convert::ToDouble(inputs[1]);
                double x2 = Convert::ToDouble(inputs[2]);
                double y2 = Convert::ToDouble(inputs[3]);
                double x3 = Convert::ToDouble(inputs[4]);
                double y3 = Convert::ToDouble(inputs[5]);

                VertexTriangle^ triangle = gcnew VertexTriangle(x1, y1, x2, y2, x3, y3);
                inscribedRadiusOutput->Text = "Inscribed Radius: " + triangle->CalculateInscribedRadius();
                circumscribedRadiusOutput->Text = "Circumscribed Radius: " + triangle->CalculateCircumscribedRadius();
                medianLengthOutput->Text = "Median Length: " + triangle->CalculateMedianLength();
                parallelMedianOutput->Text = "Parallel Median: " + triangle->CalculateParallelMedian();
            }
            catch (FormatException^)
            {
                MessageBox::Show("Invalid input format. Please enter valid numeric values.");
            }
        }
        else
        {
            MessageBox::Show("Invalid input format. Please enter six values separated by commas.");
        }
    }

    void CalculateSideButton_Click(Object^ sender, EventArgs^ e)
    {
        array<String^>^ inputs = sideInputs->Text->Split(',');

        if (inputs->Length == 3)
        {
            try
            {
                double side1 = Convert::ToDouble(inputs[0]);
                double side2 = Convert::ToDouble(inputs[1]);
                double side3 = Convert::ToDouble(inputs[2]);

                SideTriangle^ triangle = gcnew SideTriangle(side1, side2, side3);
                inscribedRadiusOutput->Text = "Inscribed Radius: " + triangle->CalculateInscribedRadius();
                circumscribedRadiusOutput->Text = "Circumscribed Radius: " + triangle->CalculateCircumscribedRadius();
                medianLengthOutput->Text = "Median Length: " + triangle->CalculateMedianLength();
                parallelMedianOutput->Text = "Parallel Median: " + triangle->CalculateParallelMedian();
            }
            catch (FormatException^)
            {
                MessageBox::Show("Invalid input format. Please enter valid numeric values.");
            }
        }
        else
        {
            MessageBox::Show("Invalid input format. Please enter three values separated by commas.");
        }
    }
};

// Entry point for the application
int main(array<System::String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // Create and run the form
    Application::Run(gcnew TriangleForm());

    return 0;
}
//end//