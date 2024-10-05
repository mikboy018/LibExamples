module fortranmath_ops
  implicit none
  contains

  subroutine fortran_add(a,b,c) bind(C, name="fortran_add")
    double precision, intent(in) :: a,b
    double precision, intent(out) :: C

    c = a + b

  end subroutine fortran_add

  subroutine fortran_div(a,b,c) bind(C, name="fortran_div")
    double precision, intent(in) :: a,b
    double precision, intent(out) :: C

    if(b < 0.00000001) then
      c = a/0.000000001
    else
      c = a/b
    end if
  end subroutine fortran_div

end module fortranmath_ops