/**
 * @param {string} val
 * @return {Object}
 */
var expect = function(val) {
    return{ 
        toBe: function(v1){
            if(v1 === val){
                return true
            }
            else{
                throw new Error("Not Equal")
            }
        },
        notToBe: function(v1){
            if(v1 !== val){
                return true
            }
            else{
                throw new Error("Equal")
            }
        }
    };
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */