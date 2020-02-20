//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#pragma once

#include "Material.h"
#include "RankTwoTensor.h"

/**
 * MaterialRankTwoCylindricalComponent uses the namespace RankTwoScalarTools to compute scalar
 * values from Rank-2 tensors.
 */
template <bool is_ad>
class RankTwoCylindricalComponentTempl : public Material
{
public:
  static InputParameters validParams();

  RankTwoCylindricalComponentTempl(const InputParameters & parameters);

protected:
  virtual void initQpStatefulProperties() override;
  virtual void computeQpProperties() override;

  const GenericMaterialProperty<RankTwoTensor, is_ad> & _tensor;

  /// Name of the stress/strain to be calculated
  const std::string _property_name;

  /// Stress/strain value returned from calculation
  GenericMaterialProperty<Real, is_ad> & _property;

  /**
   * Determines the information to be extracted from the tensor by using the
   * RankTwoScalarTools namespace, e.g., hoop strain, axial strain, etc.
   */
  MooseEnum _cylindrical_component;

  /// Points used to determine the axis of rotation
  const Point _cylindrical_axis_point1;
  const Point _cylindrical_axis_point2;

  /// The direction vector in which the scalar stress value is calculated
  Point _direction;
};

typedef RankTwoCylindricalComponentTempl<false> RankTwoCylindricalComponent;
typedef RankTwoCylindricalComponentTempl<true> ADRankTwoCylindricalComponent;
