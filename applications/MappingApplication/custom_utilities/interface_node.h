//    |  /           |
//    ' /   __| _` | __|  _ \   __|
//    . \  |   (   | |   (   |\__ `
//   _|\_\_|  \__,_|\__|\___/ ____/
//                   Multi-Physics
//
//  License:		 BSD License
//					 Kratos default license: kratos/license.txt
//
//  Main authors:    Philipp Bucher, Jordi Cotela
//
// See Master-Thesis P.Bucher
// "Development and Implementation of a Parallel
//  Framework for Non-Matching Grid Mapping"

#if !defined(KRATOS_INTERFACE_NODE_INCLUDED_H_INCLUDED )
#define  KRATOS_INTERFACE_NODE_INCLUDED_H_INCLUDED



// System includes
#include <string>
#include <iostream>


// External includes


// Project includes
#include "includes/define.h"
#include "interface_object.h"


namespace Kratos
{
  ///@addtogroup ApplicationNameApplication
  ///@{

  ///@name Kratos Globals
  ///@{

  ///@}
  ///@name Type Definitions
  ///@{

  ///@}
  ///@name  Enum's
  ///@{

  ///@}
  ///@name  Functions
  ///@{

  ///@}
  ///@name Kratos Classes
  ///@{

  /// Short class definition.
  /** Detail class definition.
  */
  class InterfaceNode : public InterfaceObject
    {
    public:
      ///@name Type Definitions
      ///@{

      /// Pointer definition of InterfaceNode
      KRATOS_CLASS_POINTER_DEFINITION(InterfaceNode);

      ///@}
      ///@name Life Cycle
      ///@{

      /// Default constructor.
      InterfaceNode(Node<3>& i_node) : InterfaceObject(i_node),  mpNode(&i_node) {  }

      /// Destructor.
      virtual ~InterfaceNode() { }


      ///@}
      ///@name Operators
      ///@{


      ///@}
      ///@name Operations
      ///@{

      bool EvaluateResult(array_1d<double, 3> global_coords, double& min_distance,
                          double distance, array_1d<double,2>& local_coords,
                          std::vector<double>& shape_function_values) override { // I am an object in the bins
          bool is_closer = false;

          if (distance < min_distance){
              min_distance = distance;
              is_closer = true;
          }

          return is_closer;
      }

      // Scalars
      double GetObjectValue(const Variable<double>& variable) override {
          return mpNode->FastGetSolutionStepValue(variable);
      }

      void SetObjectValue(const Variable<double>& variable,
                          const double value,
                          const Kratos::Flags& options,
                          const double factor) override {
          if (options.Is(MapperFlags::ADD_VALUES)) {
              mpNode->FastGetSolutionStepValue(variable) += value * factor;
          } else {
              mpNode->FastGetSolutionStepValue(variable) = value * factor;
          }
      }

      // Vectors
      array_1d<double,3> GetObjectValue(const Variable< array_1d<double,3> >& variable) override {
          return mpNode->FastGetSolutionStepValue(variable);
      }

      void SetObjectValue(const Variable< array_1d<double,3> >& variable,
                          const array_1d<double,3>& value,
                          const Kratos::Flags& options,
                          const double factor) override {
          if (options.Is(MapperFlags::ADD_VALUES)) {
              mpNode->FastGetSolutionStepValue(variable) += value * factor;
          } else {
              mpNode->FastGetSolutionStepValue(variable) = value * factor;
          }
      }

      // Functions used for Debugging
      int GetObjectId() override {
          return mpNode->Id();
      }

      void PrintNeighbors(const int CommRank) override {
          array_1d<double, 3> neighbor_coordinates = mpNode->GetValue(NEIGHBOR_COORDINATES);
          double neighbor_comm_rank = mpNode->GetValue(NEIGHBOR_RANK);
          
          PrintMatchInfo("InterfaceNode", GetObjectId(), CommRank, 
                         neighbor_comm_rank, neighbor_coordinates);
      }

      void WriteRankAndCoordinatesToVariable(const int CommRank) override {
          // This function writes the coordinates and the rank of the 
          // InterfaceObject to the variables "NEIGHBOR_COORDINATES" 
          // and "NEIGHBOR_RANK", for debugging
          array_1d<double,3> neighbor_coordinates;
          neighbor_coordinates[0] = this->X();
          neighbor_coordinates[1] = this->Y();
          neighbor_coordinates[2] = this->Z();
          mpNode->SetValue(NEIGHBOR_COORDINATES, neighbor_coordinates);
          mpNode->SetValue(NEIGHBOR_RANK, CommRank);
      }

      ///@}
      ///@name Access
      ///@{


      ///@}
      ///@name Inquiry
      ///@{


      ///@}
      ///@name Input and output
      ///@{

      /// Turn back information as a string.
      virtual std::string Info() const
      {
	       std::stringstream buffer;
         buffer << "InterfaceNode" ;
         return buffer.str();
      }

      /// Print information about this object.
      virtual void PrintInfo(std::ostream& rOStream) const {rOStream << "InterfaceNode";}

      /// Print object's data.
      virtual void PrintData(std::ostream& rOStream) const {}


      ///@}
      ///@name Friends
      ///@{


      ///@}

    protected:
      ///@name Protected static Member Variables
      ///@{


      ///@}
      ///@name Protected member Variables
      ///@{


      ///@}
      ///@name Protected Operators
      ///@{


      ///@}
      ///@name Protected Operations
      ///@{


      ///@}
      ///@name Protected  Access
      ///@{


      ///@}
      ///@name Protected Inquiry
      ///@{


      ///@}
      ///@name Protected LifeCycle
      ///@{


      ///@}

    private:
      ///@name Static Member Variables
      ///@{


      ///@}
      ///@name Member Variables
      ///@{

      Node<3>* mpNode;

      ///@}
      ///@name Private Operators
      ///@{


      ///@}
      ///@name Private Operations
      ///@{


      ///@}
      ///@name Private  Access
      ///@{


      ///@}
      ///@name Private Inquiry
      ///@{


      ///@}
      ///@name Un accessible methods
      ///@{

      /// Assignment operator.
      InterfaceNode& operator=(InterfaceNode const& rOther);

    //   /// Copy constructor.
    //   InterfaceNode(InterfaceNode const& rOther){}


      ///@}

    }; // Class InterfaceNode

  ///@}

  ///@name Type Definitions
  ///@{


  ///@}
  ///@name Input and output
  ///@{


  /// input stream function
  inline std::istream& operator >> (std::istream& rIStream,
				    InterfaceNode& rThis)
  {
      return rIStream;
  }

  /// output stream function
  inline std::ostream& operator << (std::ostream& rOStream,
				    const InterfaceNode& rThis)
  {
      rThis.PrintInfo(rOStream);
      rOStream << std::endl;
      rThis.PrintData(rOStream);

      return rOStream;
  }
  ///@}

  ///@} addtogroup block

}  // namespace Kratos.

#endif // KRATOS_INTERFACE_NODE_INCLUDED_H_INCLUDED  defined
