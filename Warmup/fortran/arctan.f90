program arctan
! Program to compute the first derivative of arctan(x) at x=sqrt(2)

IMPLICIT NONE

  integer :: i,j,h_steps
  real(8) :: x,darctan !darctan is the exact first derivative
  real(4) :: h_single
  real(4),dimension(:,:),allocatable :: single
  !single(:,1) is for h, (:,2) is for the derivative
  real(8) :: h_double
  real(8),dimension(:,:),allocatable :: double
  !double(:,1) is for h, (:,2) is for the derivative
  
  x = 0.0
  h_steps = 0
  print *, "Find first derivative of arctan(x)"
  !read in x
  write (*,'(A5)',advance="no") "x = "
  read *, x
  !read in h_steps
  print *, "h starts from 0.1"
  write (*,'(A19)',advance="no") "Number of steps = "
  read *, h_steps

  !initialize h
  h_single = 0.1
  h_double = 0.1d0
  
  allocate(single(h_steps,2),double(h_steps,2))
  
  do i=1, h_steps
    !single precision
    single(i,1) = h_single
!    single(i,2) = (atan(x + h_single)-atan(x))/h_single
    single(i,2) = (atan(x + h_single)-atan(x - h_single))/(2*h_single)
    h_single = h_single * 0.5
    !double precision
    double(i,1) = h_double
!    double(i,2) = (atan(x + h_double)-atan(x))/h_double
    double(i,2) = (atan(x + h_double)-atan(x - h_double))/(2*h_double)
    h_double = h_double * 0.5
  end do

  open(unit=11, file="out-single_3.dat", status="replace" )
  open(unit=12, file="out-double_3.dat", status="replace" )
  !get the exact first derivative
  darctan = 1/(1+x*x)
  do i=1, h_steps
    write(11,'(E16.10,2X,E16.10)') log10(single(i,1)), &
      & log10(abs((single(i,2)-darctan)/(darctan)))
    write(12,'(E16.10,2X,E16.10)') log10(double(i,1)), &
      & log10(abs((double(i,2)-darctan)/(darctan)))
  end do
  close(11)
  close(12)

  deallocate(single, double)

end program arctan
