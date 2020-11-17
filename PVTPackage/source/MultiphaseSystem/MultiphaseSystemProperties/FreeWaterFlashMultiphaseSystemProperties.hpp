/*
 * ------------------------------------------------------------------------------------------------------------
 * SPDX-License-Identifier: LGPL-2.1-only
 *
 * Copyright (c) 2018-2020 Lawrence Livermore National Security LLC
 * Copyright (c) 2018-2020 The Board of Trustees of the Leland Stanford Junior University
 * Copyright (c) 2018-2020 Total, S.A
 * Copyright (c) 2020-     GEOSX Contributors
 * All right reserved
 *
 * See top level LICENSE, COPYRIGHT, CONTRIBUTORS, NOTICE, and ACKNOWLEDGEMENTS files for details.
 * ------------------------------------------------------------------------------------------------------------
 */

#ifndef PVTPACKAGE_FREEWATERFLASHMULTIPHASESYSTEMPROPERTIES_HPP
#define PVTPACKAGE_FREEWATERFLASHMULTIPHASESYSTEMPROPERTIES_HPP

#include "MultiphaseSystem/MultiphaseSystemProperties/CompositionalMultiphaseSystemProperties.hpp"
#include "MultiphaseSystem/ComponentProperties.hpp"
#include "MultiphaseSystem/PhaseModel/CubicEOS/CubicEoSPhaseModel.hpp"

#include "pvt/pvt.hpp"

#include <map>

namespace PVTPackage
{

class FreeWaterFlashMultiphaseSystemProperties final : public CompositionalMultiphaseSystemProperties
{
public:

  FreeWaterFlashMultiphaseSystemProperties( const std::vector< pvt::PHASE_TYPE > & phases,
                                            const std::vector< pvt::EOS_TYPE > & eosTypes,
                                            const ComponentProperties & cp );

  void setWaterMoleComposition( std::vector< double > const & moleComposition );

  void setWaterFraction( double const & fraction );

  std::vector< double > const & getOilLnFugacity() const;

  std::vector< double > const & getGasLnFugacity() const;

  std::vector< double > const & getWaterLnFugacity() const;
};

}

#endif //PVTPACKAGE_FREEWATERFLASHMULTIPHASESYSTEMPROPERTIES_HPP
