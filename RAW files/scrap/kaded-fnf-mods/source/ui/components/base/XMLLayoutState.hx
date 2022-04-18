/*
 * Apache License, Version 2.0
 *
 * Copyright (c) 2021 MasterEric
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 *     http://www.apache.org/licenses/LICENSE-2.0
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// JOELwindows7: yoink from https://github.com/EnigmaEngine/EnigmaEngine/blob/stable/source/funkin/ui/component/base/XMLLayoutState.hx
/*
 * XMLLayoutState.hx
 * Provides convenience functions for creating UIs with layouts powered by XML.
 */
package ui.components.base;

import flixel.util.FlxColor;
import flixel.addons.ui.FlxUISprite;
import flixel.addons.ui.FlxUIButton;
import flixel.FlxSprite;
// import funkin.util.Util;
// import funkin.util.assets.Paths;
import flixel.text.FlxText;
import flixel.addons.ui.FlxUI;
import flixel.addons.ui.FlxUIState;
import flixel.addons.ui.FlxUITypedButton;

using hx.strings.Strings;

typedef ClickEventHandlerFn = Void->Void;

class XMLLayoutState /*extends CoreXMLState*/ extends CoreState // JOELwindows7: make sure core state. no, CORE XML STATE YESS!!
{
	private var clickEventHandlers:Map<String, ClickEventHandlerFn> = new Map();

	function getXMLId():String
	{
		// You MUST override me! Don't forget!
		throw 'You did not override getXMLId!';
	}

	override function create()
	{
		trace('Initializing a layout with XML (${getXMLId()})');
		// Make sure the XML gets loaded.
		this._xml_id = getXMLId();

		// You dumbass. You cretin. You nincompoop.
		super.create();
	}

	public override function getRequest(id:String, target:Dynamic, data:Dynamic, ?params:Array<Dynamic>):Dynamic
	{
		// If the request is to build a UI component...
		if (id.indexOf("ui_get:") == 0)
		{
			var tag = id.removeFirst("ui_get:");
			trace('XMLLayoutState received REQUEST: ui_get: $tag');
			return buildComponent(tag, target, data, params);
		}
		return null;
	}

	public override function getEvent(id:String, sender:Dynamic, data:Dynamic, ?params:Array<Dynamic>):Void
	{
		super.getEvent(id, sender, data, params);
		switch (id)
		{
			// Handle the event when a button is clicked.
			case FlxUITypedButton.CLICK_EVENT:
				trace('Retrieving onClick callback...');
				handleEventClickButton(sender, data, params);

			// Ignore these events.
			case FlxUITypedButton.DOWN_EVENT:
				return;
			case FlxUITypedButton.OVER_EVENT:
				return;
			case FlxUITypedButton.OUT_EVENT:
				return;
			default:
				trace('XMLLayoutState received EVENT: $id');
		}
	}

	function handleEventClickButton(sender:Dynamic, data:Dynamic, ?params:Array<Dynamic>)
	{
		if (sender is FlxUIButton)
		{
			var buttonSender:FlxUIButton = cast sender;
			var buttonName = buttonSender.name;

			if (buttonName != null && buttonName != '')
			{
				var callbackFn = clickEventHandlers.get(buttonName);
				if (callbackFn != null)
				{
					trace('Running registered onClick callback for $buttonName');
					callbackFn();
				}
				else
				{
					Debug.logWarn('Found no callback function for button $buttonName');
				}
			}
			else
			{
				// This happens all the time.
				// Debug.logWarn('Received button click event but name was blank.');
			}
		}
		else
		{
			Debug.logWarn('Received click event on non-TypedButton. ${HelperFunctions.getTypeName(sender)}');
		}
	}

	/**
	 * Add a callback function to be called when the specified widget is clicked.
	 * @param name The 'name' attribute of the widget originating the event.
	 * @param cb The callback function to bind to and call.
	 */
	function addClickEventHandler(name:String, cb:Void->Void)
	{
		clickEventHandlers.set(name, cb);
	}

	/**
	 * Clear all references to click event handlers.
	 */
	function clearClickEventHandlers()
	{
		clickEventHandlers.clear();
	}

	/**
	 * When an unknown tag is added to the XML, this function builds and returns a new FlxUI component based on the data.
	 * @param tag The XML tag of the element.
	 * @return The new UI element to render.
	 */
	/*override*/ public function buildComponent(tag:String, target:Dynamic, data:Dynamic, ?params:Array<Dynamic>):Dynamic
	{
		var element:Xml = cast data;
		switch (tag)
		{
			case 'background':
				var x = Std.parseInt(element.get('x'));
				var y = Std.parseInt(element.get('y'));
				var w = Std.parseInt(element.get('w'));
				var h = Std.parseInt(element.get('h'));
				var src = element.get('src');
				var core = element.get('core') == 'true';
				var color = element.get('color');

				var result = new FlxUISprite(x, y);
				result.loadGraphic(Paths.image(src, core ? 'core' : null), false, w, h);

				if (color != null && color != '')
					result.color = FlxColor.fromString(color);

				return result;
			case 'test':
				return new FlxText(0, 0, 0, "Mod Configuration", 24);
			default:
				// Debug.logWarn('XMLLayoutState: Could not build component $tag');
				// return null;
				return super.buildComponent(tag, target, data, params); // JOELwindows7: GO TO CORE XML STATE.
		}
	}
}
