module double_operations
  use iso_c_binding

  implicit none

  interface
    function fortran_add(a, b) bind(c, name="fortran_add")
      use iso_c_binding
      real(c_double), value :: a
      real(c_double), value :: b
      real(c_double) :: add_fortran
    end function fortran_add
  end interface

  interface
    function fortran_div(a, b) bind(c, name="fortran_div")
      use iso_c_binding
      real(c_double), value :: a
      real(c_double), value :: b
      real(c_double) :: div_fortran
    end function fortran_div
  end interface

  contains

  subroutine add_fortran(a, b, result)
    real :: a, b, result
    result = a + b
  end subroutine add_fortran

  subroutine div_fortran(a, b, result)
    real :: a, b, result
    if (b /= 0.0) then
      result = a / b
    else
      result = huge(0.0)  ! or some other sentinel value
    end if
  end subroutine div_fortran

end module double_operations