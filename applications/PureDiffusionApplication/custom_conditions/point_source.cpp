//    |  /           |
//    ' /   __| _` | __|  _ \   __|
//    . \  |   (   | |   (   |\__ `
//   _|\_\_|  \__,_|\__|\___/ ____/
//                   Multi-Physics
//
//  License:         BSD License
//                   Kratos default license: kratos/license.txt
//
//  Main authors:    Miguel Masó Sotomayor
//


// System includes 

// External includes 
#include "boost/smart_ptr.hpp"

// Project includes
#include "includes/define.h"
#include "pure_diffusion_application.h"
#include "custom_conditions/point_source.h"
#include "utilities/math_utils.h"

namespace Kratos
{
	//******************************************************************
	//******************************************************************
	PointSource::PointSource(IndexType NewId, GeometryType::Pointer pGeometry)
		: Condition(NewId, pGeometry)
	{
		//DO NOT ADD DOFS HERE
	}

	//******************************************************************
	//******************************************************************
	PointSource::PointSource(IndexType NewId, GeometryType::Pointer pGeometry, PropertiesType::Pointer pProperties)
		: Condition(NewId, pGeometry, pProperties)
	{
	}

	Condition::Pointer PointSource::Create(IndexType NewId, NodesArrayType const& ThisNodes,  PropertiesType::Pointer pProperties) const
	{
		return Condition::Pointer(new PointSource(NewId, GetGeometry().Create(ThisNodes), pProperties));
	}

	PointSource::~PointSource()
	{
	}

	//************************************************************************************
	//************************************************************************************
	void PointSource::CalculateRightHandSide(VectorType& rRightHandSideVector, ProcessInfo& rCurrentProcessInfo)
	{
		KRATOS_TRY
		if(rRightHandSideVector.size() != 1)
			rRightHandSideVector.resize(1,false);

		double load = GetGeometry()[0].GetSolutionStepValue(POINT_HEAT_SOURCE);
		rRightHandSideVector[0] = load;
		KRATOS_CATCH("")
	}

	//************************************************************************************
	//************************************************************************************
	void PointSource::CalculateLocalSystem(MatrixType& rLeftHandSideMatrix, VectorType& rRightHandSideVector, ProcessInfo& rCurrentProcessInfo)
	{
		KRATOS_TRY

		if(rLeftHandSideMatrix.size1() != 1)
			rLeftHandSideMatrix.resize(1,1,false);
		noalias(rLeftHandSideMatrix) = ZeroMatrix(1,1);
		if(rRightHandSideVector.size() != 1)
			rRightHandSideVector.resize(1,false);
		double load = GetGeometry()[0].GetSolutionStepValue(POINT_HEAT_SOURCE);
		rRightHandSideVector[0] = load;
		KRATOS_CATCH("")
	}


	//************************************************************************************
	//************************************************************************************
	void PointSource::EquationIdVector(EquationIdVectorType& rResult, ProcessInfo& CurrentProcessInfo)
	{
		int number_of_nodes = GetGeometry().PointsNumber();
		unsigned int index;
		unsigned int dim = 1;
		rResult.resize(number_of_nodes*dim);
		for (int i=0;i<number_of_nodes;i++)
		{
			index = i*dim;
			rResult[index] = (GetGeometry()[i].GetDof(TEMPERATURE).EquationId());			
		}
	}

	//************************************************************************************
	//************************************************************************************
	void PointSource::GetDofList(DofsVectorType& rConditionalDofList,ProcessInfo& rCurrentProcessInfo)
	{
		unsigned int dim = 1;
		rConditionalDofList.resize(GetGeometry().size()*dim);
		unsigned int index;
		for (unsigned int i=0;i<GetGeometry().size();i++)
		{
			index = i*dim;
			rConditionalDofList[index] = (GetGeometry()[i].pGetDof(TEMPERATURE));
		}
	}




}  // namespace Kratos