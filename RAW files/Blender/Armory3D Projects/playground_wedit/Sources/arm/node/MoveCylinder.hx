package arm.node;

@:keep class MoveCylinder extends armory.logicnode.LogicTree {

	var functionNodes:Map<String, armory.logicnode.FunctionNode>;

	var functionOutputNodes:Map<String, armory.logicnode.FunctionOutputNode>;

	public function new() {
		super();
		this.functionNodes = new Map();
		this.functionOutputNodes = new Map();
		notifyOnAdd(add);
	}

	override public function add() {
		var _SetObjectLocation = new armory.logicnode.SetLocationNode(this);
		var _OnUpdate_001 = new armory.logicnode.OnUpdateNode(this);
		_OnUpdate_001.property0 = "Update";
		_OnUpdate_001.addOutputs([_SetObjectLocation]);
		_SetObjectLocation.addInput(_OnUpdate_001, 0);
		_SetObjectLocation.addInput(new armory.logicnode.ObjectNode(this, ""), 0);
		var _Vector_001 = new armory.logicnode.VectorNode(this);
		var _Math = new armory.logicnode.MathNode(this);
		_Math.property0 = "Add";
		_Math.property1 = "false";
		var _Math_002 = new armory.logicnode.MathNode(this);
		_Math_002.property0 = "Add";
		_Math_002.property1 = "false";
		var _GetApplicationTime = new armory.logicnode.TimeNode(this);
		_GetApplicationTime.addOutputs([_Math_002]);
		_GetApplicationTime.addOutputs([new armory.logicnode.FloatNode(this, 0.0)]);
		_Math_002.addInput(_GetApplicationTime, 0);
		_Math_002.addInput(new armory.logicnode.FloatNode(this, 0.5), 0);
		_Math_002.addOutputs([_Math]);
		_Math.addInput(_Math_002, 0);
		_Math.addInput(new armory.logicnode.FloatNode(this, 4.0), 0);
		_Math.addOutputs([_Vector_001]);
		_Vector_001.addInput(_Math, 0);
		var _SeparateXYZ_001 = new armory.logicnode.SeparateVectorNode(this);
		var _GetObjectLocation = new armory.logicnode.GetLocationNode(this);
		_GetObjectLocation.addInput(new armory.logicnode.ObjectNode(this, ""), 0);
		_GetObjectLocation.addOutputs([_SeparateXYZ_001]);
		_SeparateXYZ_001.addInput(_GetObjectLocation, 0);
		_SeparateXYZ_001.addOutputs([new armory.logicnode.FloatNode(this, 0.0)]);
		_SeparateXYZ_001.addOutputs([_Vector_001]);
		_SeparateXYZ_001.addOutputs([_Vector_001]);
		_Vector_001.addInput(_SeparateXYZ_001, 1);
		_Vector_001.addInput(_SeparateXYZ_001, 2);
		_Vector_001.addOutputs([_SetObjectLocation]);
		_SetObjectLocation.addInput(_Vector_001, 0);
		_SetObjectLocation.addOutputs([new armory.logicnode.NullNode(this)]);
	}
}