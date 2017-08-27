import "../lib/js/src/globalStyles"
import {jsComponent as Page} from "../lib/js/src/components/page"
import {jsComponent as Resources} from "../lib/js/src/components/resources"

export default (props) => <Page {...props} children={<Resources />}></Page>