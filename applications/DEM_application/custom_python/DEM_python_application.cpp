//
// Author: Miquel Santasusana msantasusana@cimne.upc.edu
//

// System includes

#if defined(KRATOS_PYTHON)
// External includes
#include <boost/python.hpp>

// Project includes
#include "includes/define.h"
#include "DEM_application.h"
#include "custom_python/add_custom_strategies_to_python.h"
#include "custom_python/add_custom_utilities_to_python.h"
#include "custom_python/add_custom_constitutive_laws_to_python.h"

namespace Kratos
{

namespace Python
{

using namespace boost::python;

BOOST_PYTHON_MODULE(KratosDEMApplication)
{

    class_<KratosDEMApplication,
           KratosDEMApplication::Pointer,
           bases<KratosApplication>, boost::noncopyable >("KratosDEMApplication")
           ;

    AddCustomStrategiesToPython();
    AddCustomUtilitiesToPython();
    AddCustomConstitutiveLawsToPython();

    //Constitutive law
    KRATOS_REGISTER_IN_PYTHON_VARIABLE( DEM_CONTINUUM_CONSTITUTIVE_LAW_NAME )
    KRATOS_REGISTER_IN_PYTHON_VARIABLE( DEM_DISCONTINUUM_CONSTITUTIVE_LAW_NAME )
    KRATOS_REGISTER_IN_PYTHON_VARIABLE( DEM_DISCONTINUUM_CONSTITUTIVE_LAW_POINTER )
    KRATOS_REGISTER_IN_PYTHON_VARIABLE( DEM_CONTINUUM_CONSTITUTIVE_LAW_POINTER )
            
    //scheme
    KRATOS_REGISTER_IN_PYTHON_VARIABLE( DEM_INTEGRATION_SCHEME_NAME )
    KRATOS_REGISTER_IN_PYTHON_VARIABLE( DEM_INTEGRATION_SCHEME_POINTER )
            
            
    KRATOS_REGISTER_IN_PYTHON_VARIABLE( PROBABILITY_DISTRIBUTION )        
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(EXCENTRICITY_PROBABILITY_DISTRIBUTION )        

    // OPTIONS AND FLAGS
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(TOP)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(BOTTOM)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(FORCE_INTEGRATION_GROUP)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(TABLE_NUMBER)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(TABLE_VELOCITY_COMPONENT)        
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(BOUNDING_BOX_OPTION)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(ROTATION_OPTION)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(CRITICAL_TIME_OPTION)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(VIRTUAL_MASS_OPTION)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(SEARCH_CONTROL) 
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(COORDINATION_NUMBER)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(MAX_AMPLIFICATION_RATIO_OF_THE_SEARCH_RADIUS)        
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(CLEAN_INDENT_OPTION)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(TRIHEDRON_OPTION)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(ROLLING_FRICTION_OPTION)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(POISSON_EFFECT_OPTION)        
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(SHEAR_STRAIN_PARALLEL_TO_BOND_OPTION)        
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(NEIGH_INITIALIZED)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(TRIAXIAL_TEST_OPTION)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(COMPUTE_STRESS_TENSOR_OPTION)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(FIX_VELOCITIES_FLAG)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(PARTICLE_ID)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(CONTAINS_CLUSTERS)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(RANDOM_ORIENTATION)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(LOCAL_RESOLUTION_METHOD)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(COMPUTE_FEM_RESULTS_OPTION) 
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(BREAKABLE_CLUSTER)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(CONTINUUM_OPTION)
    //KRATOS_REGISTER_IN_PYTHON_VARIABLE(CLUSTER_INFORMATION) //Dangerous. Requires adding ClusterInformation to python
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(CLUSTER_FILE_NAME)
            
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(INITIAL_VELOCITY_X_VALUE)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(INITIAL_VELOCITY_Y_VALUE)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(INITIAL_VELOCITY_Z_VALUE)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(INITIAL_ANGULAR_VELOCITY_X_VALUE)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(INITIAL_ANGULAR_VELOCITY_Y_VALUE)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(INITIAL_ANGULAR_VELOCITY_Z_VALUE)

    // *************** Continuum only BEGIN *************
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(DELTA_OPTION)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(CASE_OPTION)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(SKIN_SPHERE)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(PARTICLE_COHESION)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(PARTICLE_TENSION)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(COHESIVE_GROUP)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(PROPERTIES_ID)        
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(CONTACT_MESH_OPTION)
    //KRATOS_REGISTER_IN_PYTHON_VARIABLE(FAILURE_CRITERION_OPTION)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(CONCRETE_TEST_OPTION)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(IF_BOUNDARY_ELEMENT)
    // *************** Continuum only END ***************

    // MATERIAL PARAMETERS

    KRATOS_REGISTER_IN_PYTHON_VARIABLE(NODAL_MASS_COEFF)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(PARTICLE_MOMENT_OF_INERTIA)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(ROLLING_FRICTION)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(HISTORICAL_MIN_K)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(PARTICLE_INERTIA)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(PARTICLE_DENSITY)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(PARTICLE_FRICTION)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(PARTICLE_STATIC_FRICTION_COEF)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(PARTICLE_DYNAMIC_FRICTION_COEF)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(COEFFICIENT_OF_RESTITUTION)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(PARTICLE_ROTATION_DAMP_RATIO)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(DAMPING_GAMMA)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(K_NORMAL)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(K_TANGENTIAL)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(CONTACT_RADIUS)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(MAX_STRESS)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(ALPHA)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(ALPHA_FUNCTION)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(GAMMA)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(EXCENTRICITY)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(EXCENTRICITY_STANDARD_DEVIATION)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(FABRIC_COEFFICIENT)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(POISSON_VALUE)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(INTERNAL_COHESION)  
            
    // *************** Nano-particle only BEGIN *************
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(CATION_CONCENTRATION)
    // *************** Nano-particle only END *************

    // *************** Continuum only BEGIN *************
    // *************** Dempack Constitutive Law only BEGIN *************            
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(SLOPE_FRACTION_N1)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(SLOPE_FRACTION_N2)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(SLOPE_FRACTION_N3)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(SLOPE_LIMIT_COEFF_C1)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(SLOPE_LIMIT_COEFF_C2)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(SLOPE_LIMIT_COEFF_C3)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(YOUNG_MODULUS_PLASTIC)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(PLASTIC_YIELD_STRESS)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(DAMAGE_FACTOR)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(SHEAR_ENERGY_COEF)
    // *************** Dempack Constitutive Law only END ***************               
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(DONZE_G1)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(DONZE_G2)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(DONZE_G3)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(DONZE_MAX_DEF)
            
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(CONTACT_FAILURE)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(CONTACT_ORIENTATION)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(CONTACT_SIGMA)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(CONTACT_TAU)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(FAILURE_CRITERION_STATE)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(UNIDIMENSIONAL_DAMAGE)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(CONTACT_SIGMA_MIN)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(CONTACT_TAU_ZERO)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(CONTACT_INTERNAL_FRICC)
    // *************** Continuum only END *************

    // GEOMETRIC PARAMETERS

    // *************** Continuum only BEGIN *************
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(LOCAL_CONTACT_AREA_HIGH)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(LOCAL_CONTACT_AREA_LOW)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(MEAN_CONTACT_AREA)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(REPRESENTATIVE_VOLUME)    
    // *************** Continuum only END ***************

    // INLET PARAMETERS
    
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(INLET_START_TIME)    
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(INLET_STOP_TIME)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(INLET_NUMBER_OF_PARTICLES) 
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(STANDARD_DEVIATION) 
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(MAX_RAND_DEVIATION_ANGLE)
    KRATOS_REGISTER_IN_PYTHON_3D_VARIABLE_WITH_COMPONENTS(LINEAR_VELOCITY)
    KRATOS_REGISTER_IN_PYTHON_3D_VARIABLE_WITH_COMPONENTS(INLET_INITIAL_VELOCITY)
    KRATOS_REGISTER_IN_PYTHON_3D_VARIABLE_WITH_COMPONENTS(INLET_INITIAL_PARTICLES_VELOCITY)        
                
    // KINEMATICS

    KRATOS_REGISTER_IN_PYTHON_3D_VARIABLE_WITH_COMPONENTS(PARTICLE_ROTATION_ANGLE)
    KRATOS_REGISTER_IN_PYTHON_3D_VARIABLE_WITH_COMPONENTS(EULER_ANGLES)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(ORIENTATION_REAL) // JIG: SHOULD BE REMOVED IN THE FUTURE
    KRATOS_REGISTER_IN_PYTHON_3D_VARIABLE_WITH_COMPONENTS(ORIENTATION_IMAG) // JIG: SHOULD BE REMOVED IN THE FUTURE
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(ORIENTATION)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(AUX_ORIENTATION)
    KRATOS_REGISTER_IN_PYTHON_3D_VARIABLE_WITH_COMPONENTS(PRINCIPAL_MOMENTS_OF_INERTIA)        
    KRATOS_REGISTER_IN_PYTHON_3D_VARIABLE_WITH_COMPONENTS(DELTA_DISPLACEMENT)
    KRATOS_REGISTER_IN_PYTHON_3D_VARIABLE_WITH_COMPONENTS(DELTA_ROTA_DISPLACEMENT)
    KRATOS_REGISTER_IN_PYTHON_3D_VARIABLE_WITH_COMPONENTS(LOCAL_ANGULAR_VELOCITY)
    KRATOS_REGISTER_IN_PYTHON_3D_VARIABLE_WITH_COMPONENTS(LOCAL_AUX_ANGULAR_VELOCITY)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(VELOCITY_START_TIME)    
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(VELOCITY_STOP_TIME)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(ANGULAR_VELOCITY_START_TIME)    
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(ANGULAR_VELOCITY_STOP_TIME)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(RIGID_BODY_MOTION)

    // FORCE AND MOMENTUM

    KRATOS_REGISTER_IN_PYTHON_3D_VARIABLE_WITH_COMPONENTS(PARTICLE_MOMENT)
    KRATOS_REGISTER_IN_PYTHON_3D_VARIABLE_WITH_COMPONENTS(MAX_ROTA_MOMENT)
    KRATOS_REGISTER_IN_PYTHON_3D_VARIABLE_WITH_COMPONENTS(ROLLING_RESISTANCE_MOMENT)
    KRATOS_REGISTER_IN_PYTHON_3D_VARIABLE_WITH_COMPONENTS(ELASTIC_FORCES)
    KRATOS_REGISTER_IN_PYTHON_3D_VARIABLE_WITH_COMPONENTS(CONTACT_FORCES)
    KRATOS_REGISTER_IN_PYTHON_3D_VARIABLE_WITH_COMPONENTS(RIGID_ELEMENT_FORCE)
    KRATOS_REGISTER_IN_PYTHON_3D_VARIABLE_WITH_COMPONENTS(TANGENTIAL_ELASTIC_FORCES)
    KRATOS_REGISTER_IN_PYTHON_3D_VARIABLE_WITH_COMPONENTS(FORCE_REACTION)
    KRATOS_REGISTER_IN_PYTHON_3D_VARIABLE_WITH_COMPONENTS(MOMENT_REACTION)        
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(DEM_PRESSURE)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(DEM_NODAL_AREA)
            
    // ENERGY

    KRATOS_REGISTER_IN_PYTHON_VARIABLE(PARTICLE_ELASTIC_ENERGY)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(PARTICLE_TRANSLATIONAL_KINEMATIC_ENERGY)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(PARTICLE_ROTATIONAL_KINEMATIC_ENERGY)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(PARTICLE_GRAVITATIONAL_ENERGY)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(PARTICLE_INELASTIC_VISCODAMPING_ENERGY)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(PARTICLE_INELASTIC_FRICTIONAL_ENERGY)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(COMPUTE_ENERGY_OPTION)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(GLOBAL_DAMPING)        
            
    // *************** Continuum only BEGIN *************
    KRATOS_REGISTER_IN_PYTHON_3D_VARIABLE_WITH_COMPONENTS(INITIAL_ROTA_MOMENT)
    //KRATOS_REGISTER_IN_PYTHON_VARIABLE(PARTICLE_BLOCK_CONTACT_FORCE)
    KRATOS_REGISTER_IN_PYTHON_3D_VARIABLE_WITH_COMPONENTS(EXTERNAL_APPLIED_FORCE)
    KRATOS_REGISTER_IN_PYTHON_3D_VARIABLE_WITH_COMPONENTS(EXTERNAL_APPLIED_MOMENT)
    KRATOS_REGISTER_IN_PYTHON_3D_VARIABLE_WITH_COMPONENTS(LOCAL_CONTACT_FORCE)
    //KRATOS_REGISTER_IN_PYTHON_VARIABLE(PARTICLE_CONTACT_FORCES )
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(NEIGHBOUR_SIZE)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(NEIGHBOUR_RATIO)

    // CONCRETE TEST

    KRATOS_REGISTER_IN_PYTHON_VARIABLE(FIXED_VEL_TOP)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(FIXED_VEL_BOT)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(AREA_VERTICAL_TAPA)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(AREA_VERTICAL_CENTRE)

    // TENSION

    KRATOS_REGISTER_IN_PYTHON_VARIABLE(DEM_STRESS_TENSOR)

    // APPLIED LOADS

    KRATOS_REGISTER_IN_PYTHON_VARIABLE(BLAST_RADIUS)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(BLAST_CURVE)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(BLAST_PRESSURE_MAX)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(BLAST_TIME_PRESSURE_MAX)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(BLAST_SHAPE_FACTOR)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(BLAST_TIME_DELAY)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(BLAST_BOREHOLE)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(BLAST_NPOINTS)
    KRATOS_REGISTER_IN_PYTHON_3D_VARIABLE_WITH_COMPONENTS(BLAST_COORDINATES_1)
    KRATOS_REGISTER_IN_PYTHON_3D_VARIABLE_WITH_COMPONENTS(BLAST_COORDINATES_2)
    KRATOS_REGISTER_IN_PYTHON_3D_VARIABLE_WITH_COMPONENTS(BLAST_COORDINATES_3)
    KRATOS_REGISTER_IN_PYTHON_3D_VARIABLE_WITH_COMPONENTS(BLAST_COORDINATES_4)
    KRATOS_REGISTER_IN_PYTHON_3D_VARIABLE_WITH_COMPONENTS(BLAST_COORDINATES_5)
    KRATOS_REGISTER_IN_PYTHON_3D_VARIABLE_WITH_COMPONENTS(BLAST_COORDINATES_6)
    KRATOS_REGISTER_IN_PYTHON_3D_VARIABLE_WITH_COMPONENTS(BLAST_COORDINATES_7)
    KRATOS_REGISTER_IN_PYTHON_3D_VARIABLE_WITH_COMPONENTS(BLAST_COORDINATES_8)
    // *************** Continuum only END *************

    // DUMMIES INT AND DOUBLE VARIABLES
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(DUMMY_SWITCH)

    //EXPORTS
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(EXPORT_ID)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(EXPORT_PARTICLE_FAILURE_ID)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(PRINT_EXPORT_ID)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(PRINT_STRESS_TENSOR_OPTION)

    //For DEM_FEM Element
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(LOCAL_DAMP_RATIO)
    
    //SLS DEM-FEM
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(WALL_FRICTION)        
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(SHEAR_STRESS)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(NON_DIMENSIONAL_VOLUME_WEAR)        
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(IMPACT_WEAR)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(SEVERITY_OF_WEAR)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(BRINELL_HARDNESS)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(COMPUTE_WEAR)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(IMPACT_WEAR_SEVERITY)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(WALL_COHESION)
     
    //DEM_CLUSTERS        
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(CLUSTER_VOLUME)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(CHARACTERISTIC_LENGTH)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(SPRAYED_MATERIAL)
    
    //BOUNDING BOX
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(BOUNDING_BOX_START_TIME)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(BOUNDING_BOX_STOP_TIME)
    
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(RIGID_FACE_ROTA_SPEED)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(RIGID_FACE_AXIAL_SPEED)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(RIGID_FACE_PROP_ID)
    KRATOS_REGISTER_IN_PYTHON_3D_VARIABLE_WITH_COMPONENTS(RIGID_FACE_ROTA_ORIGIN_COORD)
    KRATOS_REGISTER_IN_PYTHON_3D_VARIABLE_WITH_COMPONENTS(RIGID_FACE_ROTA_AXIAL_DIR)
    KRATOS_REGISTER_IN_PYTHON_3D_VARIABLE_WITH_COMPONENTS(RIGID_FACE_ROTA_GLOBAL_VELOCITY)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(RIGID_FACE_BEGIN_TIME)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(RIGID_FACE_END_TIME)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(RIGID_FACE_FLAG)
                   
    //OPTIMIZATION
  
    // *************** Thermal only BEGIN *************
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(HEATFLUX)
    KRATOS_REGISTER_IN_PYTHON_VARIABLE(THERMAL_CONDUCTIVITY)        
    // *************** Thermal only END ***************  
    
}

}  // namespace Python.

}  // namespace Kratos.

#endif // KRATOS_PYTHON defined
