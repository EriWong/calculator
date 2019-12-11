// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#include "pch.h"
#include "GraphingNumPad.xaml.h"
#include "Views/NumberPad.xaml.h"
#include "Controls/CalculatorButton.h"
#include "CalcViewModel/Common/LocalizationSettings.h"

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
    { NumbersAndOperatorsEnum::Sin, { L"sin()", 4 } },
    { NumbersAndOperatorsEnum::Cos, { L"cos()", 4 } },
    { NumbersAndOperatorsEnum::Tan, { L"tan()", 4 } },
    { NumbersAndOperatorsEnum::Sec, { L"sec()", 4 } },
    { NumbersAndOperatorsEnum::Csc, { L"csc()", 4 } },
    { NumbersAndOperatorsEnum::Cot, { L"cot()", 4 } },
    { NumbersAndOperatorsEnum::InvSin, { L"arcsin()", 7 } },
    { NumbersAndOperatorsEnum::InvCos, { L"arccos()", 7 } },
    { NumbersAndOperatorsEnum::InvTan, { L"arctan()", 7 } },
    { NumbersAndOperatorsEnum::InvSec, { L"arcsec()", 7 } },
    { NumbersAndOperatorsEnum::InvCsc, { L"arccsc()", 7 } },
    { NumbersAndOperatorsEnum::InvCot, { L"arccot()", 7 } },
    { NumbersAndOperatorsEnum::Sinh, { L"sinh()", 5 } },
    { NumbersAndOperatorsEnum::Cosh, { L"cosh()", 5 } },
    { NumbersAndOperatorsEnum::Tanh, { L"tanh()", 5 } },
    { NumbersAndOperatorsEnum::Sech, { L"sech()", 5 } },
    { NumbersAndOperatorsEnum::Csch, { L"csch()", 5 } },
    { NumbersAndOperatorsEnum::Coth, { L"coth()", 5 } },
    { NumbersAndOperatorsEnum::InvSinh, { L"arcsinh()", 8 } },
    { NumbersAndOperatorsEnum::InvCosh, { L"arccosh()", 8 } },
    { NumbersAndOperatorsEnum::InvTanh, { L"arctanh()", 8 } },
    { NumbersAndOperatorsEnum::InvSech, { L"arcsech()", 8 } },
    { NumbersAndOperatorsEnum::InvCsch, { L"arccsch()", 8 } },
    { NumbersAndOperatorsEnum::InvCoth, { L"arccoth()", 8 } },
    { NumbersAndOperatorsEnum::Abs, { L"abs()", 4 } },
    { NumbersAndOperatorsEnum::Floor, { L"floor()", 6 } },
    { NumbersAndOperatorsEnum::Ceil, { L"ceiling()", 8 } },
    { NumbersAndOperatorsEnum::Pi, { L"\u03C0", 1 } },
    { NumbersAndOperatorsEnum::Euler, { L"e", 1 } },
    { NumbersAndOperatorsEnum::XPower2, { L"^2", 2 } },
    { NumbersAndOperatorsEnum::Cube, { L"^3", 2 } },
    { NumbersAndOperatorsEnum::XPowerY, { L"^", 1 } },
    { NumbersAndOperatorsEnum::TenPowerX, { L"10^", 3 } },
    { NumbersAndOperatorsEnum::LogBase10, { L"log()", 4 } },
    { NumbersAndOperatorsEnum::LogBaseE, { L"ln()", 3 } },
    { NumbersAndOperatorsEnum::Sqrt, { L"sqrt()", 5 } },
    { NumbersAndOperatorsEnum::CubeRoot, { L"cbrt()", 5 } },
    { NumbersAndOperatorsEnum::YRootX, { L"root(b,x)", 5 } },
    { NumbersAndOperatorsEnum::TwoPowerX, { L"2^", 2 } },
    { NumbersAndOperatorsEnum::LogBaseX, { L"log(b, x)", 4 } },
    { NumbersAndOperatorsEnum::EPowerX, { L"e^", 4 } },
    { NumbersAndOperatorsEnum::Abs, { L"abs()", 4 } },
    { NumbersAndOperatorsEnum::X, { L"x", 1 } },
    { NumbersAndOperatorsEnum::Y, { L"y", 1 } },
    { NumbersAndOperatorsEnum::OpenParenthesis, { L"(", 1 } },
    { NumbersAndOperatorsEnum::CloseParenthesis, { L")", 1 } },
    { NumbersAndOperatorsEnum::Equals, { L"=", 1 } },
    { NumbersAndOperatorsEnum::Divide, { L"/", 1 } },
    { NumbersAndOperatorsEnum::Multiply, { L"*", 1 } },
    { NumbersAndOperatorsEnum::Subtract, { L"-", 1 } },
    { NumbersAndOperatorsEnum::Add, { L"+", 1 } },
    { NumbersAndOperatorsEnum::Invert, { L"1/", 2 } },
    { NumbersAndOperatorsEnum::Negate, { L"-", 1 } },
    { NumbersAndOperatorsEnum::GreaterThan, { L">", 1 } },
    { NumbersAndOperatorsEnum::GreaterThanOrEqualTo, { L"\u2265", 1 } },
    { NumbersAndOperatorsEnum::LessThan, { L"<", 1 } },
    { NumbersAndOperatorsEnum::LessThanOrEqualTo, { L"\u2264", 1 } },
    { NumbersAndOperatorsEnum::Zero, { L"0", 1 } },
    { NumbersAndOperatorsEnum::One, { L"1", 1 } },
    { NumbersAndOperatorsEnum::Two, { L"2", 1 } },
    { NumbersAndOperatorsEnum::Three, { L"3", 1 } },
    { NumbersAndOperatorsEnum::Four, { L"4", 1 } },
    { NumbersAndOperatorsEnum::Five, { L"5", 1 } },
    { NumbersAndOperatorsEnum::Six, { L"6", 1 } },
    { NumbersAndOperatorsEnum::Seven, { L"7", 1 } },
    { NumbersAndOperatorsEnum::Eight, { L"8", 1 } },
    { NumbersAndOperatorsEnum::Nine, { L"9", 1 } },
    { NumbersAndOperatorsEnum::Decimal, { L".", 1 } },
};

GraphingNumPad::GraphingNumPad()
{
    InitializeComponent();
    const auto& localizationSettings = CalculatorApp::Common::LocalizationSettings::GetInstance();
    DecimalSeparatorButton->Content = localizationSettings.GetDecimalSeparator();
    Num0Button->Content = localizationSettings.GetDigitSymbolFromEnUsDigit('0');
    Num1Button->Content = localizationSettings.GetDigitSymbolFromEnUsDigit('1');
    Num2Button->Content = localizationSettings.GetDigitSymbolFromEnUsDigit('2');
    Num3Button->Content = localizationSettings.GetDigitSymbolFromEnUsDigit('3');
    Num4Button->Content = localizationSettings.GetDigitSymbolFromEnUsDigit('4');
    Num5Button->Content = localizationSettings.GetDigitSymbolFromEnUsDigit('5');
    Num6Button->Content = localizationSettings.GetDigitSymbolFromEnUsDigit('6');
    Num7Button->Content = localizationSettings.GetDigitSymbolFromEnUsDigit('7');
    Num8Button->Content = localizationSettings.GetDigitSymbolFromEnUsDigit('8');
    Num9Button->Content = localizationSettings.GetDigitSymbolFromEnUsDigit('9');
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
    m_targetEIA->ETB->SubmitEquation();
}

void GraphingNumPad::ClearButton_Clicked(Platform::Object ^ sender, Windows::UI::Xaml::RoutedEventArgs ^ e)
{
    m_targetEIA->ETB->SetEquationText(L"<math xmlns=\"http://www.w3.org/1998/Math/MathML\"></math>");
}

void GraphingNumPad::BackSpaceButton_Clicked(Platform::Object ^ sender, Windows::UI::Xaml::RoutedEventArgs ^ e)
{
    m_targetEIA->ETB->BackSpace();
}
