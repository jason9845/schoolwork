// Matrix inv(*this); // Same matrix
// Matrix id(this->identity()); // Identity matrix of the same size
//
// // Gauss-Jordan Reduction to calculate the inverse
// for(int i = 0; i < r; i++){
// 	for(int j = 0; j < c; j++){
// 		if(i!=j){
// 			double ratio = inv.el(j, i)/inv.el(i, i);
// 			for(int k = 0; k < r; k++){
// 				inv.el(j, k) -= ratio * inv.el(i, k);
// 				id.el(j, k) -= ratio * id.el(i, k);
// 			}
// 		}
// 	}
// }
// for(int i = 0; i < r; i++){
// 	double divisor = inv.el(i, i);
// 	for(int j = 0; j < c; j++){
// 		inv.el(i, j) /= divisor;
// 		id.el(i, j) /= divisor;
// 	}
// }
//
// return id;
