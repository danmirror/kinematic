/*
 * 
 *  ||-----|-------|------>
 *  coxa    femur   tibia
 *  
 *             .'.  beta
 *           .'   '.
 *  ||......'       '.
 *  ||    alpha
 *  
 *  gama
 *  
 */

const float cx=2;   //coxa
const float fm=6.2; //femur
const float tb=8.3; // tibia
float L, L1;
float alpha, alpha1,alpha2,beta,gama;


void calc_IK(float x, float y, float z)
{
  L1=sqrt(sq(x)+sq(y));
  gama=atan(x/y)/PI*180;
  L=sqrt(sq(L1-cx)+sq(z));
  beta=acos((sq(tb)+sq(fm)-sq(L))/(2*tb*fm))/PI*180;
  alpha1=acos(z/L)/PI*180;
  alpha2=acos((sq(fm)+sq(L)-sq(tb))/(2*fm*L))/PI*180;
  alpha=alpha1+alpha2;
  
  
  Serial2.print("gama= ");
  Serial2.print(gama);
  Serial2.print(", alpha= ");
  Serial2.print(alpha);
  Serial2.print(", beta= ");
  Serial2.print(beta);
  Serial2.println();
}

void set_traj(float x_move, float y_move, float z_offset){
  double iteration = y_move ;
  
  degree_1= gama+330; 
  degree_2 = alpha;
  degree_3 = beta+512;

  /* 
   *        ..
   *      .'
   *    .'
   */
  while(iteration <= x_move){
    calc_IK(x_move, iteration, z_offset); //contoh x,y,z
    run_servo();
    iteration += RATE;
  }
  
  /* 
   *        ..
   *          '.
   *            '.
   */
  while(iteration >= y_move){
    calc_IK(x_move, iteration, z_offset); //contoh x,y,z
    run_servo();
    iteration -= RATE;
  }
  
}
