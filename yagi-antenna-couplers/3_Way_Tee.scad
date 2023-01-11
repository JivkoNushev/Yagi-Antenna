////////////////////////////////////////////////////////
// Created by Paul Tibble - 11/5/18                   //
// https://www.thingiverse.com/Paul_Tibble/about      //
// Please consider tipping, if you find this useful.  //
////////////////////////////////////////////////////////


//use the outer diameter of pipe
inner_diameter = 33;
//
wall_thickness = 3;
//from center of fitting to end of port
length = 40;
//use the wall thickness of the pipe
recess_thickness = 2;
//how far the pipe enters into the fitting
recess_depth = 20;


//do not change these
$fn = 100*1;
inner_radius = inner_diameter/2;
outer_diameter = inner_diameter + (wall_thickness*2);
outer_radius = outer_diameter/2;
fillet_radius = wall_thickness/2;

module create_center_bore() {
    sphere(inner_radius+0.001);
}

module create_center(){
    sphere(outer_radius+0.001);
}
module create_center_recess_bore() {
    sphere((inner_radius-recess_thickness)+0.001);
}

module create_center_recess(){
    sphere(inner_radius+0.001);
}

module create_x_recess(){
    rotate([0,90,0])translate([0,0,(length-recess_depth)/2])cylinder(length-recess_depth,inner_radius+0.001,inner_radius+0.001,true);
}
module create_x_recess_bore(){
    rotate([0,90,0])translate([0,0,length/2])cylinder(length,(inner_radius-recess_thickness),(inner_radius-recess_thickness),true);
}
module create_x_bore(){
    rotate([0,90,0])translate([0,0,length])cylinder(length*2,inner_radius,inner_radius,true);
}
module create_x_outer(){
    rotate([0,90,0]){
        rotate_extrude(angle=360,convexity=10){
            square([outer_radius,length-fillet_radius]);
            translate([outer_radius-fillet_radius,length-fillet_radius,0])circle(fillet_radius);
            translate([0,length-fillet_radius,0])square([outer_radius-fillet_radius,fillet_radius]);
        }
    }
}

module create_mx_recess(){
    rotate([0,0,180])create_x_recess();
}
module create_mx_recess_bore(){
    rotate([0,0,180])create_x_recess_bore();
}
module create_mx_bore(){
    rotate([0,0,180])create_x_bore();
}
module create_mx_outer(){
    rotate([0,0,180])create_x_outer();
}

module create_y_recess(){
    rotate([0,0,90])create_x_recess();
}
module create_y_recess_bore(){
    rotate([0,0,90])create_x_recess_bore();
}
module create_y_bore(){
    rotate([0,0,90])create_x_bore();
}
module create_y_outer(){
    rotate([0,0,90])create_x_outer();
}

module create_my_recess(){
    rotate([0,0,-90])create_x_recess();
}
module create_my_recess_bore(){
    rotate([0,0,-90])create_x_recess_bore();
}
module create_my_bore(){
    rotate([0,0,-90])create_x_bore();
}
module create_my_outer(){
    rotate([0,0,-90])create_x_outer();
}

module create_z_recess(){
    rotate([0,-90,0])create_x_recess();
}
module create_z_recess_bore(){
    rotate([0,-90,0])create_x_recess_bore();
}
module create_z_bore(){
    rotate([0,-90,0])create_x_bore();
}
module create_z_outer(){
    rotate([0,-90,0])create_x_outer();
}

module create_mz_recess(){
    rotate([0,90,0])create_x_recess();
}
module create_mz_recess_bore(){
    rotate([0,90,0])create_x_recess_bore();
}
module create_mz_bore(){
    rotate([0,90,0])create_x_bore();
}
module create_mz_outer(){
    rotate([0,90,0])create_x_outer();
}
//difference(){
union(){
    difference(){
        union(){
            create_center();
            create_x_outer();
            create_mx_outer();
            create_y_outer();
            //create_my_outer();
            //create_z_outer();
            //create_mz_outer();
        }
        create_center_bore();
        create_x_bore();
        create_mx_bore();
        create_y_bore();
        //create_my_bore();
        //create_z_bore();
        //create_mz_bore();
    }

    difference(){
        union(){
            create_center_recess();
            create_x_recess();
            create_mx_recess();
            create_y_recess();
            //create_my_recess();
            //create_z_recess();
            //create_mz_recess();           
        }
        create_center_recess_bore();
        create_x_recess_bore();
        create_mx_recess_bore();
        create_y_recess_bore();
        //create_my_recess_bore();
        //create_z_recess_bore();
        //create_mz_recess_bore();
    }
}
//translate([0,0,-100])cube([200,200,200],true);
//}