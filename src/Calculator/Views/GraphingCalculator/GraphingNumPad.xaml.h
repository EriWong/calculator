// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#pragma once

#include "Views\GraphingCalculator\GraphingNumPad.g.h"
#include "CalcViewModel/GraphingCalculator/GraphingCalculatorViewModel.h"
#include "Views/GraphingCalculator/EquationInputArea.xaml.h"
#include "CalcViewModel/Common/CalculatorButtonUser.h"

namespace CalculatorApp
{
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class GraphingNumPad sealed 
	{
	public:
		GraphingNumPad();

        property EquationInputArea ^ TargetEIA
        {
            EquationInputArea^ get()
            {
                return m_targetEIA;
            }

            void set(EquationInputArea ^ value)
            {
                m_targetEIA = value;
            }
        }

    private:
        void ShiftButton_Check(_In_ Platform::Object ^ sender, _In_ Windows::UI::Xaml::RoutedEventArgs ^ e);
        void ShiftButton_Uncheck(_In_ Platform::Object ^ sender, _In_ Windows::UI::Xaml::RoutedEventArgs ^ e);
        void TrigFlyoutShift_Toggle(_In_ Platform::Object ^ sender, _In_ Windows::UI::Xaml::RoutedEventArgs ^ e);
        void TrigFlyoutHyp_Toggle(_In_ Platform::Object ^ sender, _In_ Windows::UI::Xaml::RoutedEventArgs ^ e);
        void FlyoutButton_Clicked(_In_ Platform::Object ^ sender, _In_ Windows::UI::Xaml::RoutedEventArgs ^ e);
        void ShiftButton_IsEnabledChanged(_In_ Platform::Object ^ sender, _In_ Windows::UI::Xaml::DependencyPropertyChangedEventArgs ^ e);
        void SetOperatorRowVisibility();
        void SetTrigRowVisibility();
        void Button_Clicked(_In_ Platform::Object ^ sender, _In_ Windows::UI::Xaml::DependencyPropertyChangedEventArgs ^ e);
        void SubmitButton_Clicked(Platform::Object ^ sender, Windows::UI::Xaml::RoutedEventArgs ^ e);

        EquationInputArea ^ m_targetEIA;

        std::unordered_map<CalculatorApp::NumbersAndOperatorsEnum, std::pair<Platform::String ^, int>> buttonOutput = {
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
            { CalculatorApp::NumbersAndOperatorsEnum::Invert, { L"1/", 1 } },
        };
    };
}
