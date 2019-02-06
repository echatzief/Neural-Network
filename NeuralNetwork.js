function sigmoid(num){
    return m = 1/(1+Math.exp(-num));
}

function dsigmoid(y){
    return y*(1-y);
}
class NeuralNetwork{
    constructor(numInputs,numHidden,numOutputs){
        this.input_nodes=numInputs;
        this.hidden_nodes=numHidden;
        this.output_nodes=numOutputs;
        this.lr=0.1;

        console.log(this.input_nodes,this.hidden_nodes,this.output_nodes);

        //Create the matrixes of the neural network
        this.weight_IH= new Matrix(this.hidden_nodes,this.input_nodes);
        this.weight_HO= new Matrix(this.output_nodes,this.hidden_nodes);
        this.bias_H=new Matrix(this.hidden_nodes,1);
        this.bias_O=new Matrix(this.output_nodes,1);

        //Randomize the weights
        this.weight_HO.randomize();
        this.weight_IH.randomize();
        this.bias_H.randomize();
        this.bias_O.randomize();
    }

    feedForward(input){

       // -------------------------------- FEED FORWARD ALGORITHM ----------------------//
       input = Matrix.fromArray(input);

       //------------------------- Hidden Layer ----------------------------- //

       //First the weights
       let hidden = Matrix.multiply(this.weight_IH,input);
       
       //The bias
       hidden.add(this.bias_H);

       //Activation function
       hidden.map(sigmoid);


       //---------------------- Output Layer --------------------------------//

       let output = Matrix.multiply(this.weight_HO,hidden);

       //The bias
       output.add(this.bias_O);

       //Activation function
       output.map(sigmoid);

        return output.toArray();
    }

    train(inputs,answers){


        // --------------------------- CALCULATE ERROR AND WEIGHT TWEAKING ----------//
        inputs = Matrix.fromArray(inputs);
        let hidden = Matrix.multiply(this.weight_IH, inputs);
        hidden.add(this.bias_H);
        // activation function!
        hidden.map(sigmoid);

        let output = Matrix.multiply(this.weight_HO, hidden);
        output.add(this.bias_O);
        output.map(sigmoid);
        //------------------------- Hidden Layer Weight Tweak ---------------------//
        
        let targets = Matrix.fromArray(answers);
        
        let output_error = Matrix.substract(targets,output);


        //Calculate the delta
        let gradient_HO=Matrix.map(output,dsigmoid); //O(1-O)
        gradient_HO.multiply(output_error); //e*O(1-O)
        gradient_HO.multiply(this.lr);

        
        //Change the bias
        this.bias_O.add(gradient_HO);      

        let output_delta_weights=Matrix.multiply(gradient_HO,Matrix.tranpose(hidden));


        //Change the weight
        this.weight_HO.add(output_delta_weights);

        //------------------------- Input Layer Weight Tweak ---------------------//
        
        let hidden_weights_transposed=Matrix.tranpose(this.weight_HO);
        
        let hidden_error=Matrix.multiply(hidden_weights_transposed,output_error);

        //Calculate the delta
        let gradient_IH=Matrix.map(hidden,dsigmoid); //O(1-O)
        gradient_IH.multiply(hidden_error); //e*O(1-O)
        gradient_IH.multiply(this.lr);

        //Change the bias
        this.bias_H.add(gradient_IH);

        let hidden_delta_weights=Matrix.multiply(gradient_IH,Matrix.tranpose(inputs));

        //Change the weight
        this.weight_IH.add(hidden_delta_weights);

    }
}