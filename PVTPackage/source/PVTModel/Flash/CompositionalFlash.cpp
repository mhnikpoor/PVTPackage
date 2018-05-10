#include "PVTModel/Flash/CompositionalFlash.hpp"
#include "PVTModel/ComponentProperties.hpp"

namespace PVTPackage
{
	CompositionalFlash::~CompositionalFlash()
	{
		for (size_t i = 0; i != m_PhaseTypes.size(); ++i)
		{
			delete m_PhaseModel[m_PhaseTypes[i]];
		}
	}

	CompositionalFlash::CompositionalFlash(std::vector<PHASE_TYPE> phase_types, std::vector<EOS_TYPE> eos_types,
	                                       ComponentProperties* comp_props): m_PhaseTypes(std::move(phase_types)),
	                                                                         m_EoSTypes(std::move(eos_types)),
	                                                                         m_ComponentsProperties(comp_props)
	{
		for (size_t i = 0; i != m_PhaseTypes.size(); ++i)
		{
			m_PhaseModel[m_PhaseTypes[i]] = new CubicEoSPhaseModel(m_ComponentsProperties, m_EoSTypes[i], m_PhaseTypes[i]);
		}
	}

	std::vector<double> CompositionalFlash::ComputeWilsonGasOilKvalue(double Pressure, double Temperature) const
	{
		const auto nbc = m_ComponentsProperties->NComponents;
		const auto& Tc = m_ComponentsProperties->Tc;
		const auto& Pc = m_ComponentsProperties->Pc;
		const auto& Omega = m_ComponentsProperties->Omega;

		std::vector<double> Kval(nbc);

		//Gas-Oil 
		for (auto i = 0; i < nbc; i++)
		{
			Kval[i] = Pc[i] / Pressure * exp(5.37*(1 + Omega[i])*(1 - Tc[i] / Temperature));
		}

		return Kval;
	}

	std::vector<double> CompositionalFlash::ComputeWaterGasKvalue(double Pressure, double Temperature) const
	{
		const auto nbc = m_ComponentsProperties->NComponents;
		const auto water_index = m_ComponentsProperties->WaterIndex;
		std::vector<double> Kval(nbc, 0);
		Kval[water_index] = exp(-4844.168051 / Temperature + 12.93022442)*1e5 / Pressure;
		return Kval;

	}

	std::vector<double> CompositionalFlash::ComputeWaterOilKvalue(double Pressure, double Temperature) const
	{
		const auto nbc = m_ComponentsProperties->NComponents;
		return std::vector<double>(nbc, 0);
	}
}


