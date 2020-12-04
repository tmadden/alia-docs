#include "demo.hpp"

namespace unready_copier {

void
demo_ui(html::context ctx, duplex<int> n, duplex<int> m)
{
    // clang-format off
/// [unready-copier]
html::text(ctx, alia::printf(ctx, "N is %d.", n));
html::text(ctx, "What would you like to set N to?");
html::input(ctx, m);
html::button(ctx, "Set It!", n <<= m);
/// [unready-copier]
    // clang-format on
}

void
init_demo(std::string dom_id)
{
    static alia::system the_system;
    static html::system the_dom;

    initialize(the_dom, the_system, dom_id, [](html::context ctx) {
        demo_ui(
            ctx,
            enforce_validity(ctx, get_state(ctx, 0)),
            enforce_validity(ctx, get_state(ctx, empty<int>())));
    });
}

static demo the_demo("unready-copier", init_demo);

} // namespace unready_copier

namespace action_operators {

void
demo_ui(html::context ctx, duplex<int> n)
{
    // clang-format off
/// [action-operators]
html::text(ctx, alia::printf(ctx, "N is %d.", n));
html::button(ctx, "Double", n *= 2);
html::button(ctx, "Halve", n /= 2);
html::button(ctx, "Square", n *= n);
html::button(ctx, "Increment", ++n);
html::button(ctx, "Decrement", n--);
html::button(ctx, "Reset", n <<= 1);
/// [action-operators]
    // clang-format on
}

void
init_demo(std::string dom_id)
{
    static alia::system the_system;
    static html::system the_dom;

    initialize(the_dom, the_system, dom_id, [](html::context ctx) {
        demo_ui(ctx, enforce_validity(ctx, get_state(ctx, 1)));
    });
}

static demo the_demo("action-operators", init_demo);

} // namespace action_operators

namespace action_combining {

void
demo_ui(html::context ctx, duplex<int> m, duplex<int> n)
{
    // clang-format off
/// [action-combining]
html::text(ctx, alia::printf(ctx, "M is %d and N is %d.", m, n));
html::button(ctx, "Increment M", ++m);
html::button(ctx, "Increment N", ++n);
html::button(ctx, "Reset Both", (m <<= 0, n <<= 0));
/// [action-combining]
    // clang-format on
}

void
init_demo(std::string dom_id)
{
    static alia::system the_system;
    static html::system the_dom;

    initialize(the_dom, the_system, dom_id, [](html::context ctx) {
        demo_ui(ctx, get_state(ctx, 0), get_state(ctx, 0));
    });
}

static demo the_demo("action-combining", init_demo);

} // namespace action_combining

namespace action_latching {

void
demo_ui(html::context ctx, duplex<int> in_hand, duplex<int> in_bank)
{
    // clang-format off
/// [action-latching]
html::text(ctx,
    alia::printf(ctx,
        "You have %d coin(s) in hand and %d in the bank.",
        in_hand, in_bank));
html::button(ctx, "Pick Up a Coin", ++in_hand);
html::button(ctx, "Deposit Your Coins", (in_hand <<= 0, in_bank += in_hand));
/// [action-latching]
    // clang-format on
}

void
init_demo(std::string dom_id)
{
    static alia::system the_system;
    static html::system the_dom;

    initialize(the_dom, the_system, dom_id, [](html::context ctx) {
        demo_ui(ctx, get_state(ctx, 0), get_state(ctx, 0));
    });
}

static demo the_demo("action-latching", init_demo);

} // namespace action_latching

namespace action_binding {

void
demo_ui(html::context ctx, duplex<int> duration)
{
    // clang-format off
/// [action-binding]
animation_timer timer(ctx);

alia_if(timer.is_active())
{
    html::text(ctx, alia::printf(ctx, "%d ms left.", timer.ticks_left()));
}
alia_else
{
    html::text(ctx, "The timer is stopped.");
}
alia_end

html::text(ctx, "Enter a duration in milliseconds:");
html::input(ctx, duration);
html::button(ctx, "Start", timer.start() << duration);
/// [action-binding]
    // clang-format on
}

void
init_demo(std::string dom_id)
{
    static alia::system the_system;
    static html::system the_dom;

    initialize(the_dom, the_system, dom_id, [](html::context ctx) {
        demo_ui(ctx, enforce_validity(ctx, get_state(ctx, empty<int>())));
    });
}

static demo the_demo("action-binding", init_demo);

} // namespace action_binding

namespace action_demo {

void
demo_ui(html::context ctx, duplex<std::string> message)
{
    // clang-format off
/// [callback-demo]
// Define a UI for inputting a message.
html::text(ctx, "Enter a message for your browser's console:");
html::input(ctx, message);

// Create an action that takes a message as a parameter.
auto sender = callback(
    [](std::string message) { std::cout << message << std::endl; });

// Bind the message to the action and hook them up to a button.
html::button(ctx, "Send", sender << message);
/// [callback-demo]
    // clang-format on
}

void
init_demo(std::string dom_id)
{
    static alia::system the_system;
    static html::system the_dom;

    initialize(the_dom, the_system, dom_id, [](html::context ctx) {
        demo_ui(ctx, get_state(ctx, std::string()));
    });
}

static demo the_demo("callback-demo", init_demo);

} // namespace action_demo