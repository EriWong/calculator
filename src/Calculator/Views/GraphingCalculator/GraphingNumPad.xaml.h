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

        EquationInputArea ^ m_targetEIA;
        //void OnDataContextChanged(Windows::UI::Xaml::FrameworkElement ^ sender, Windows::UI::Xaml::DataContextChangedEventArgs ^ args);
	};
}
