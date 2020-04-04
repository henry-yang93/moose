//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#pragma once

#include "ElementVectorPostprocessor.h"

class ElementVariableVectorPostprocessor;

/**
 * Base class VectorPostprocessors operating on elemental variables.
 */
class ElementVariableVectorPostprocessor : public ElementVectorPostprocessor
{
public:
  static InputParameters validParams();

  ElementVariableVectorPostprocessor(const InputParameters & parameters);
};
