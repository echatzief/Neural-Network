class Matrix{
    constructor(rows,cols){
        this.rows=rows;
        this.cols=cols;
        this.data = [];

        //Create the matrix
        for(let i=0;i<this.rows;i++){
            this.data[i]= [];

            for(let j=0;j<this.cols;j++){
                this.data[i][j]=0;
            }
        }
    }

    static tranpose(a){
        let m = new Matrix(a.cols,a.rows);

        for(let i=0;i<a.cols;i++){
            for(let j=0;j<a.rows;j++){
                m.data[i][j]=a.data[j][i];
            }
        }
        return m;
    }

    static fromArray(arr){
        let m = new Matrix(arr.length,1);

        for(let i=0;i<arr.length;i++){
            m.data[i][0]=arr[i];
        }
        
        return m;
    }

    toArray(){
        let arr=[]
        for(let i=0;i<this.rows;i++){
            for(let j=0;j<this.cols;j++){
               arr.push(this.data[i][j]);
            }
        }
        return arr;
    }
    //Multiply two matrixes
    static multiply(a,b){
        // Matrix product
        if (a.cols !== b.rows) {
            console.log('Columns of A must match rows of B.')
            return undefined;
        }
        let result = new Matrix(a.rows, b.cols);
        for (let i = 0; i < result.rows; i++) {
            for (let j = 0; j < result.cols; j++) {
                // Dot product of values in col
                let sum = 0;
                for (let k = 0; k < a.cols; k++) {
                sum += a.data[i][k] * b.data[k][j];
                }
                result.data[i][j] = sum;
            }
        }
        return result;
    }
    //Multiply a matrix with number
    multiply(n){
        if (n instanceof Matrix) {
            // hadamard product
            for (let i = 0; i < this.rows; i++) {
              for (let j = 0; j < this.cols; j++) {
                this.data[i][j] *= n.data[i][j];
              }
            }
        } else {
            // Scalar product
            for (let i = 0; i < this.rows; i++) {
              for (let j = 0; j < this.cols; j++) {
                this.data[i][j] *= n;
              }
            }
        }
    }

    //Initialize the array with random stuff
    randomize(){
        for(let i=0;i<this.rows;i++){
            for(let j=0;j<this.cols;j++){
                this.data[i][j]=Math.floor(Math.random() *2 -1)
            }
        }
    }

    static substract(a,b){
        //Return a new metrics
        if(a.rows == b.rows && a.cols ==b.cols){
            let result = new Matrix(a.rows,a.cols);
            
            for(let i=0;i<a.rows;i++){
                for(let j=0;j<a.cols;j++){
                    result.data[i][j]=a.data[i][j]-b.data[i][j];        
                }
            }
           // result.print();
            return result;
        }
        else{
            console.log("Dimensions doesn't match"); 
        }
    }
    //Add operation with n as number or matrix
    add(n){

        if(n instanceof Matrix){
            if(n.rows == this.rows && n.cols==this.cols){
                for(let i=0;i<this.rows;i++){
                    for(let j=0;j<this.cols;j++){
                        this.data[i][j]+=n.data[i][j];
                    }
                }
            }
            else{
                console.log("Dimensions doesn't match");    
            }
        }
        else{
            for(let i=0;i<this.rows;i++){
                for(let j=0;j<this.cols;j++){
                    this.data[i][j]+=n;
                }
            }
        }
    }

    static map(arr,func){

        let result = new Matrix(arr.rows,arr.cols);

        for(let i=0;i<result.rows;i++){
            for(let j=0;j<result.cols;j++){
                result.data[i][j]=func(arr.data[i][j]);
            }
        } 
        return result;
    }
    //Apply a function to every element
    map(func){
        for(let i=0;i<this.rows;i++){
            for(let j=0;j<this.cols;j++){
                this.data[i][j]=func(this.data[i][j]);
            }
        } 
    }

    print(){
        console.table(this.data);
    }
}