
// colwise matrix representation
let a = [ 1,2,3,4,1,4,9,16];
// vector 
let b = [ 0.6, 2.2, 4.8, 8.4];

let d1=4;
let d2=2;

let A =  new Array(d1*d2);

let B =  new Array(d1);

let M1 = new Module.deconv();
let X = new Array(d2);

M1.init(d1,d2);

// colwise matrix mapping
for (let i = 0; i < d1*d2; i++) {
    M1.setA(i, a[i]);
    A[i]= M1.getA(i);

}


for (let i = 0; i < d1; i++) {
    M1.setb(i, b[i]);
    B[i]= M1.getb(i);

}

console.log(A);
console.log('--------');
console.log(B);

M1.calc();


for (let i = 0;i < d2; i++) {
	X[i] = M1.getRes(i);
}
console.log('========');

console.log(X);



