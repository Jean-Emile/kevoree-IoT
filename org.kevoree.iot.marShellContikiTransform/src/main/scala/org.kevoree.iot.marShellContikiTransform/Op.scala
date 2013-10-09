/**
 * Licensed under the GNU LESSER GENERAL PUBLIC LICENSE, Version 3, 29 June 2007;
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.gnu.org/licenses/lgpl-3.0.txt
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
/**
 * Licensed under the GNU LESSER GENERAL PUBLIC LICENSE, Version 3, 29 June 2007;
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * 	http://www.gnu.org/licenses/lgpl-3.0.txt
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
package org.kevoree.iot.modelTransform

/**
 * Created by jed
 * User: jedartois@gmail.com
 * Date: 27/03/12
 * Time: 13:32
 */

object Op extends Enumeration {

  val ADD_REPO = Value("0");
  val MERGE = Value("1");

  /* components */
  val UDI_C= Value("2")
  val AIN_C = Value("3")
  val RIN_C = Value("4")

  /* bindings */
  val ABI_C = Value("5")
  val RBI_C = Value("6")
  val UBI_C = Value("7")

   /* groups */
  val UPDATE_GROUP= Value("8")
  val ADD_GROUP = Value("9")
  val ADD_TO_GROUP = Value("10")
  val REMOVE_GROUP = Value("11")
  val ADD_BINDING_GROUP = Value("12")
  val REMOVE_BINDING_GROUP = Value("13")

  /* node */
  val UPDATE_NODE= Value("14")
  val ADD_NODE = Value("15")
  val REMOVE_NODE = Value("16")



}