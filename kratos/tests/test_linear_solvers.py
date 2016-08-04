﻿from __future__ import print_function, absolute_import, division
import KratosMultiphysics
import KratosMultiphysics.KratosUnittest as KratosUnittest
import os

def GetFilePath(fileName):
    return os.path.dirname(os.path.realpath(__file__)) + "/" + fileName


class TestLinearSolvers(KratosUnittest.TestCase):
    
    def _RunParametrized(self, my_params_string ):
        all_settings = KratosMultiphysics.Parameters( my_params_string )
        
        for i in range(all_settings["test_list"].size()):
            settings = all_settings["test_list"][i]
            self._auxiliary_test_function(settings)
    
    def _auxiliary_test_function(self, settings):
        space = KratosMultiphysics.UblasSparseSpace()
        
        #read the matrices
        A = KratosMultiphysics.CompressedMatrix()
        KratosMultiphysics.ReadMatrixMarketMatrix(GetFilePath("A.mm"),A)
        
        Aoriginal = KratosMultiphysics.CompressedMatrix(A) #create a copy of A
        
        n = A.Size1()
        b = KratosMultiphysics.Vector(n)
        space.SetToZeroVector(b)
        b[1] = 1.0
        
        x = KratosMultiphysics.Vector(n)
        #KratosMultiphysics.ReadMatrixMarketVector("b.mm",b)

        boriginal = KratosMultiphysics.Vector(b) #create a copy of b
        
        space.SetToZeroVector(x)
        #space.SetToZeroVector(boriginal)
        #space.UnaliasedAdd(boriginal, 1.0, b) #boriginal=1*bs          

        #construct the solver
        import new_linear_solver_factory
        linear_solver = new_linear_solver_factory.ConstructSolver(settings)
        
        #solve
        linear_solver.Solve(A,x,b)    
        
        #test the results
        tmp = KratosMultiphysics.Vector(n)
        tmp *= 0.0
        space.Mult(Aoriginal,x,tmp)
        
        check = KratosMultiphysics.Vector(n)
        check = boriginal - tmp
 
        achieved_norm = space.TwoNorm(check)
        
        tolerance = 1e-9
        if(settings.Has("tolerance")):
            tolerance = settings["tolerance"].GetDouble() 
        
        target_norm = tolerance*space.TwoNorm(boriginal)

        self.assertTrue(achieved_norm < target_norm)

        
        

    def test_cg_in_core(self):
        self._RunParametrized("""
            {
                "test_list" : [
                    {
                        "solver_type" : "CGSolver",
                        "tolerance" : 1.0e-6,
                        "max_iteration" : 500,
                        "preconditioner_type" : "DiagonalPreconditioner"
                    },
                    {
                        "solver_type" : "CGSolver",
                        "tolerance" : 1.0e-6,
                        "max_iteration" : 1000,
                        "preconditioner_type" : "None"
                    }
                ]
            }
            """)

    def test_bicgstab_in_core(self):
        self._RunParametrized("""
            {
                "test_list" : [
                    {
                        "solver_type" : "BICGSTABSolver",
                        "tolerance" : 1.0e-6,
                        "max_iteration" : 500,
                        "preconditioner_type" : "ILU0Preconditioner",
                        "scaling": false
                    },
                    {
                        "solver_type" : "BICGSTABSolver",
                        "tolerance" : 1.0e-6,
                        "max_iteration" : 500,
                        "preconditioner_type" : "ILU0Preconditioner",
                        "scaling": false
                    },
                    {
                        "solver_type" : "BICGSTABSolver",
                        "tolerance" : 1.0e-6,
                        "max_iteration" : 500,
                        "preconditioner_type" : "DiagonalPreconditioner"
                    },
                    {
                        "solver_type" : "BICGSTABSolver",
                        "tolerance" : 1.0e-6,
                        "max_iteration" : 500,
                        "preconditioner_type" : "None"
                    }
                ]
            }
            """)
        
    def test_skyline_lu(self):
        self._RunParametrized("""
            {
                "test_list" : [
                    {
                        "solver_type" : "SkylineLUFactorizationSolver",
                        "scaling": false
                    }
                ]
            }
            """)

    def test_superlu(self):
        self._RunParametrized("""
            {
                "test_list" : [
                    {
                        "solver_type" : "SuperLUSolver",
                        "scaling": false
                    },
                    {
                        "solver_type" : "SuperLUIterativeSolver",
                        "scaling": false
                    },
                    {
                        "solver_type" : "SuperLUIterativeSolver",
                        "scaling": true
                    }
                ]
            }
            """)

    def test_pastix(self):
        self._RunParametrized("""
            {
                "test_list" : [
                    {
                        "solver_type" : "PastixSolver",
                        "solution_method": "Direct",
                            "tolerance":1e-6,
                            "max_iteration":100,
                            "gmres_krylov_space_dimension":100,
                            "ilu_level_of_fill":1,
                            "is_symmetric":false,
                            "verbosity":0,
                            "scaling": false,
                            "block_size": 1,
                        "use_block_matrices_if_possible" : true
                    }
                ]
            }
            """)

    def test_amgcl(self):
        self._RunParametrized("""
            {
                "test_list" : [
                    {

                        "solver_type" : "AMGCL",
                        "smoother_type":"spai0",
                        "krylov_type": "cg",
                        "coarsening_type": "ruge_stuben",
                        "max_iteration": 100,
                        "provide_coordinates": false,
                        "gmres_krylov_space_dimension": 100,
                        "verbosity" : 0,
                        "tolerance": 1e-6,
                        "scaling": false,
                        "block_size": 1,
                        "use_block_matrices_if_possible" : true,
                        "coarse_enough" : 500
                    },
                    {

                        "solver_type" : "AMGCL",
                        "smoother_type":"spai0",
                        "krylov_type": "gmres",
                        "coarsening_type": "aggregation",
                        "max_iteration": 100,
                        "provide_coordinates": false,
                        "gmres_krylov_space_dimension": 100,
                        "verbosity" : 0,
                        "tolerance": 1e-6,
                        "scaling": false,
                        "block_size": 1,
                        "use_block_matrices_if_possible" : true,
                        "coarse_enough" : 5000
                    },
                    {

                        "solver_type" : "AMGCL",
                        "smoother_type":"ilu0",
                        "krylov_type": "bicgstab",
                        "coarsening_type": "aggregation",
                        "max_iteration": 100,
                        "provide_coordinates": false,
                        "gmres_krylov_space_dimension": 100,
                        "verbosity" : 0,
                        "tolerance": 1e-6,
                        "scaling": false,
                        "block_size": 1,
                        "use_block_matrices_if_possible" : true,
                        "coarse_enough" : 5000
                    },
                    {

                        "solver_type" : "AMGCL",
                        "smoother_type":"ilu0",
                        "krylov_type": "bicgstabl",
                        "coarsening_type": "aggregation",
                        "max_iteration": 100,
                        "provide_coordinates": false,
                        "gmres_krylov_space_dimension": 100,
                        "verbosity" : 0,
                        "tolerance": 1e-6,
                        "scaling": false,
                        "block_size": 1,
                        "use_block_matrices_if_possible" : true,
                        "coarse_enough" : 5000
                    }
                ]
            }
            """)
        
if __name__ == '__main__':
    KratosUnittest.main()