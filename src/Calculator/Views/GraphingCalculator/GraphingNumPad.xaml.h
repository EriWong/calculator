// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#pragma once

#include "Views\GraphingCalculator\GraphingNumPad.g.h"
#include "CalcViewModel/GraphingCalculator/GraphingCalculatorViewModel.h"
#include "Views/GraphingCalculator/EquationInputArea.xaml.h"

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

        EquationInputArea ^ m_targetEIA;

        std::unordered_map<std::wstring, std::pair<std::wstring, int>> buttonOutput = {
            { L"Sin", { L"sin()", 4 } },
            { L"Cos", { L"cos()", 4 } },
            { L"Tan", { L"tan()", 4 } },
            { L"Sec", { L"sec()", 4 } },
            { L"Csc", { L"csc()", 4 } },
            { L"Cot", { L"cot()", 4 } },
            { L"InvSin", { L"arcsin()", 7 } },
            { L"InvCos", { L"arccos()", 7 } },
            { L"InvTan", { L"arctan()", 7 } },
            { L"InvSec", { L"arcsec()", 7 } },
            { L"InvCsc", { L"arccsc()", 7 } },
            { L"InvCot", { L"arccot()", 7 } },
            { L"Sinh", { L"sinh()", 5 } },
            { L"Cosh", { L"cosh()", 5 } },
            { L"Tanh", { L"tanh()", 5 } },
            { L"Sech", { L"sech()", 5 } },
            { L"Csch", { L"csch()", 5 } },
            { L"Coth", { L"coth()", 5 } },
            { L"InvSinh", { L"arcsinh()", 8 } },
            { L"InvCosh", { L"arccosh()", 8 } },
            { L"InvTanh", { L"arctanh()", 8 } },
            { L"InvSech", { L"arcsech()", 8 } },
            { L"InvCsch", { L"arccsch()", 8 } },
            { L"InvCoth", { L"arccoth()", 8 } },
            { L"Abs", { L"abs()", 4 } },
            { L"Floor", { L"floor()", 6 } },
            { L"Ceil", { L"ceiling()", 8 } },
            { L"Pi", { L"\u03C0", 1 } },
            { L"Euler", { L"e", 1 } },
            { L"XPower2", { L"^2", 2 } },
            { L"Cube", { L"^3", 2 } },
            { L"XPowerY", { L"^", 1 } },
            { L"TenPowerX", { L"10^", 3 } },
            { L"LogBase10", { L"log()", 4 } },
            { L"LogBaseE", { L"ln()", 3 } },
            { L"Sqrt", { L"sqrt()", 5 } },
            { L"CubeRoot", { L"cbrt()", 5 } },
            { L"YRootX", { L"root(b,x)", 5 } },
            { L"TwoPowerX", { L"2^", 2 } },
            { L"LogBaseX", { L"log(b, x)", 4 } },
            { L"EPowerX", { L"e^", 4 } },
            { L"Abs", { L"abs()", 4 } },
            { L"X", { L"x", 1 } },
            { L"Y", { L"y", 1 } },
            { L"OpenParenthesis", { L"(", 1 } },
            { L"CloseParenthesis", { L")", 1 } },
            { L"Equals", { L"=", 1 } },
            { L"Divide", { L"/", 1 } },
            { L"Multiply", { L"*", 1 } },
            { L"Subtract", { L"-", 1 } },
            { L"Add", { L"+", 1 } },
        };
	};
}
