// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#include "pch.h"
#include "GraphingNumPad.xaml.h"
#include "Views/NumberPad.xaml.h"
#include "Controls/CalculatorButton.h"

using namespace CalculatorApp;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

static const std::unordered_map<CalculatorApp::NumbersAndOperatorsEnum, std::pair<Platform::String ^, int>> buttonOutput = {
    { CalculatorApp::NumbersAndOperatorsEnum::Sin, { L"sin()", 4 } },
    { CalculatorApp::NumbersAndOperatorsEnum::Cos, { L"cos()", 4 } },
    { CalculatorApp::NumbersAndOperatorsEnum::Tan, { L"tan()", 4 } },
    { CalculatorApp::NumbersAndOperatorsEnum::Sec, { L"sec()", 4 } },
    { CalculatorApp::NumbersAndOperatorsEnum::Csc, { L"csc()", 4 } },
    { CalculatorApp::NumbersAndOperatorsEnum::Cot, { L"cot()", 4 } },
    { CalculatorApp::NumbersAndOperatorsEnum::InvSin, { L"arcsin()", 7 } },
    { CalculatorApp::NumbersAndOperatorsEnum::InvCos, { L"arccos()", 7 } },
    { CalculatorApp::NumbersAndOperatorsEnum::InvTan, { L"arctan()", 7 } },
    { CalculatorApp::NumbersAndOperatorsEnum::InvSec, { L"arcsec()", 7 } },
    { CalculatorApp::NumbersAndOperatorsEnum::InvCsc, { L"arccsc()", 7 } },
    { CalculatorApp::NumbersAndOperatorsEnum::InvCot, { L"arccot()", 7 } },
    { CalculatorApp::NumbersAndOperatorsEnum::Sinh, { L"sinh()", 5 } },
    { CalculatorApp::NumbersAndOperatorsEnum::Cosh, { L"cosh()", 5 } },
    { CalculatorApp::NumbersAndOperatorsEnum::Tanh, { L"tanh()", 5 } },
    { CalculatorApp::NumbersAndOperatorsEnum::Sech, { L"sech()", 5 } },
    { CalculatorApp::NumbersAndOperatorsEnum::Csch, { L"csch()", 5 } },
    { CalculatorApp::NumbersAndOperatorsEnum::Coth, { L"coth()", 5 } },
    { CalculatorApp::NumbersAndOperatorsEnum::InvSinh, { L"arcsinh()", 8 } },
    { CalculatorApp::NumbersAndOperatorsEnum::InvCosh, { L"arccosh()", 8 } },
    { CalculatorApp::NumbersAndOperatorsEnum::InvTanh, { L"arctanh()", 8 } },
    { CalculatorApp::NumbersAndOperatorsEnum::InvSech, { L"arcsech()", 8 } },
    { CalculatorApp::NumbersAndOperatorsEnum::InvCsch, { L"arccsch()", 8 } },
    { CalculatorApp::NumbersAndOperatorsEnum::InvCoth, { L"arccoth()", 8 } },
    { CalculatorApp::NumbersAndOperatorsEnum::Abs, { L"abs()", 4 } },
    { CalculatorApp::NumbersAndOperatorsEnum::Floor, { L"floor()", 6 } },
    { CalculatorApp::NumbersAndOperatorsEnum::Ceil, { L"ceiling()", 8 } },
    { CalculatorApp::NumbersAndOperatorsEnum::Pi, { L"\u03C0", 1 } },
    { CalculatorApp::NumbersAndOperatorsEnum::Euler, { L"e", 1 } },
    { CalculatorApp::NumbersAndOperatorsEnum::XPower2, { L"^2", 2 } },
    { CalculatorApp::NumbersAndOperatorsEnum::Cube, { L"^3", 2 } },
    { CalculatorApp::NumbersAndOperatorsEnum::XPowerY, { L"^", 1 } },
    { CalculatorApp::NumbersAndOperatorsEnum::TenPowerX, { L"10^", 3 } },
    { CalculatorApp::NumbersAndOperatorsEnum::LogBase10, { L"log()", 4 } },
    { CalculatorApp::NumbersAndOperatorsEnum::LogBaseE, { L"ln()", 3 } },
    { CalculatorApp::NumbersAndOperatorsEnum::Sqrt, { L"sqrt()", 5 } },
    { CalculatorApp::NumbersAndOperatorsEnum::CubeRoot, { L"cbrt()", 5 } },
    { CalculatorApp::NumbersAndOperatorsEnum::YRootX, { L"root(b,x)", 5 } },
    { CalculatorApp::NumbersAndOperatorsEnum::TwoPowerX, { L"2^", 2 } },
    { CalculatorApp::NumbersAndOperatorsEnum::LogBaseX, { L"log(b, x)", 4 } },
    { CalculatorApp::NumbersAndOperatorsEnum::EPowerX, { L"e^", 4 } },
    { CalculatorApp::NumbersAndOperatorsEnum::Abs, { L"abs()", 4 } },
    { CalculatorApp::NumbersAndOperatorsEnum::X, { L"x", 1 } },
    { CalculatorApp::NumbersAndOperatorsEnum::Y, { L"y", 1 } },
    { CalculatorApp::NumbersAndOperatorsEnum::OpenParenthesis, { L"(", 1 } },
    { CalculatorApp::NumbersAndOperatorsEnum::CloseParenthesis, { L")", 1 } },
    { CalculatorApp::NumbersAndOperatorsEnum::Equals, { L"=", 1 } },
    { CalculatorApp::NumbersAndOperatorsEnum::Divide, { L"/", 1 } },
    { CalculatorApp::NumbersAndOperatorsEnum::Multiply, { L"*", 1 } },
    { CalculatorApp::NumbersAndOperatorsEnum::Subtract, { L"-", 1 } },
    { CalculatorApp::NumbersAndOperatorsEnum::Add, { L"+", 1 } },
    { CalculatorApp::NumbersAndOperatorsEnum::Invert, { L"1/", 2 } },
    { CalculatorApp::NumbersAndOperatorsEnum::Negate, { L"-", 1 } },
    { CalculatorApp::NumbersAndOperatorsEnum::GreaterThan, { L">", 1 } },
    { CalculatorApp::NumbersAndOperatorsEnum::GreaterThanOrEqualTo, { L"\u2265", 1 } },
    { CalculatorApp::NumbersAndOperatorsEnum::LessThan, { L"<", 1 } },
    { CalculatorApp::NumbersAndOperatorsEnum::LessThanOrEqualTo, { L"\u2264", 1 } },
};

GraphingNumPad::GraphingNumPad()
{
    InitializeComponent();
}

void GraphingNumPad::ShiftButton_Check(_In_ Platform::Object ^ /*sender*/, _In_ Windows::UI::Xaml::RoutedEventArgs ^ /*e*/)
{
    SetOperatorRowVisibility();
}

void GraphingNumPad::ShiftButton_Uncheck(_In_ Platform::Object ^ sender, _In_ Windows::UI::Xaml::RoutedEventArgs ^ /*e*/)
{
    ShiftButton->IsChecked = false;
    SetOperatorRowVisibility();

    GraphingNumPad::Button_Clicked(sender, nullptr);
}

void GraphingNumPad::TrigFlyoutShift_Toggle(_In_ Platform::Object ^ /*sender*/, _In_ Windows::UI::Xaml::RoutedEventArgs ^ /*e*/)
{
    SetTrigRowVisibility();
}

void GraphingNumPad::TrigFlyoutHyp_Toggle(_In_ Platform::Object ^ /*sender*/, _In_ Windows::UI::Xaml::RoutedEventArgs ^ /*e*/)
{
    SetTrigRowVisibility();
}

void GraphingNumPad::FlyoutButton_Clicked(_In_ Platform::Object ^ sender, _In_ Windows::UI::Xaml::RoutedEventArgs ^ /*e*/)
{
    this->HypButton->IsChecked = false;
    this->TrigShiftButton->IsChecked = false;
    this->Trigflyout->Hide();
    this->FuncFlyout->Hide();
    this->InequalityFlyout->Hide();

    GraphingNumPad::Button_Clicked(sender, nullptr);
}

void GraphingNumPad::ShiftButton_IsEnabledChanged(_In_ Platform::Object ^ /*sender*/, _In_ Windows::UI::Xaml::DependencyPropertyChangedEventArgs ^ /*e*/)
{
    SetOperatorRowVisibility();
}

void GraphingNumPad::SetTrigRowVisibility()
{
    bool isShiftChecked = TrigShiftButton->IsChecked->Value;
    bool isHypeChecked = HypButton->IsChecked->Value;

    InverseHyperbolicTrigFunctions->Visibility = ::Visibility::Collapsed;
    InverseTrigFunctions->Visibility = ::Visibility::Collapsed;
    HyperbolicTrigFunctions->Visibility = ::Visibility::Collapsed;
    TrigFunctions->Visibility = ::Visibility::Collapsed;

    if (isShiftChecked && isHypeChecked)
    {
        InverseHyperbolicTrigFunctions->Visibility = ::Visibility::Visible;
    }
    else if (isShiftChecked && !isHypeChecked)
    {
        InverseTrigFunctions->Visibility = ::Visibility::Visible;
    }
    else if (!isShiftChecked && isHypeChecked)
    {
        HyperbolicTrigFunctions->Visibility = ::Visibility::Visible;
    }
    else
    {
        TrigFunctions->Visibility = ::Visibility::Visible;
    }
}

void GraphingNumPad::Button_Clicked(Platform::Object ^ sender, Windows::UI::Xaml::DependencyPropertyChangedEventArgs ^ /*e*/)
{
    auto button = dynamic_cast<CalculatorApp::Controls::CalculatorButton ^>(sender);
    auto id = button->ButtonId;
    auto output = buttonOutput.find(id);
    m_targetEIA->ETB->InsertText(output->second.first, output->second.second);
}

void GraphingNumPad::SetOperatorRowVisibility()
{
    ::Visibility rowVis, invRowVis;
    if (ShiftButton->IsChecked->Value)
    {
        rowVis = ::Visibility::Collapsed;
        invRowVis = ::Visibility::Visible;
    }
    else
    {
        rowVis = ::Visibility::Visible;
        invRowVis = ::Visibility::Collapsed;
    }

    Row1->Visibility = rowVis;
    InvRow1->Visibility = invRowVis;
}

void GraphingNumPad::SubmitButton_Clicked(Platform::Object ^ sender, Windows::UI::Xaml::RoutedEventArgs ^ e)
{
    m_targetEIA->ETB->SubmitEq();
}
