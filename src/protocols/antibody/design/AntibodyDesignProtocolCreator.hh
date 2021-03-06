// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:
//
// (c) Copyright Rosetta Commons Member Institutions.
// (c) This file is part of the Rosetta software suite and is made available under license.
// (c) The Rosetta software is developed by the contributing members of the Rosetta Commons.
// (c) For more information, see http://www.rosettacommons.org. Questions about this can be
// (c) addressed to University of Washington CoMotion, email: license@uw.edu.

/// @file protocols//AntibodyDesignProtocolCreator.hh
/// @brief
/// @author Jared Adolf-Bryfogle (jadolfbr@gmail.com)

#ifndef INCLUDED_protocols_antibody_design_AntibodyDesignProtocolCreator_hh
#define INCLUDED_protocols_antibody_design_AntibodyDesignProtocolCreator_hh

#include <protocols/moves/MoverCreator.hh>

namespace protocols {
namespace antibody {
namespace design {


class AntibodyDesignProtocolCreator : public protocols::moves::MoverCreator {
public:

	// XRW TEMP  virtual protocols::moves::MoverOP create_mover() const;
	// XRW TEMP  virtual std::string keyname() const;
	// XRW TEMP  static std::string mover_name();
	protocols::moves::MoverOP create_mover() const override;
	std::string keyname() const override;
	void provide_xml_schema( utility::tag::XMLSchemaDefinition & xsd ) const override;



};

} //design
} //antibody
} //protocols

#endif //protocols_antibody_design_AntibodyDesignProtocolCreator_hh
